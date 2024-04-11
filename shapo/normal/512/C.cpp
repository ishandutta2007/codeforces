#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int MAXP = 100500;

bool is_prime[MAXP];

typedef vector< int > vi;

const int MAXN = 300;

int ans[MAXN];
int rev[MAXN];
int rev1[MAXN];
int sm[MAXN][MAXN];
int n, arr[MAXN];
bool used[MAXN];

void
gen_primes()
{
    for (int i = 0; i < MAXP; ++i) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAXP; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAXP; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

bool
try_kuhn(int x)
{
    if (used[x]) {
        return false;
    }
    used[x] = true;
    for (int j = 0; j < n; ++j) {
        if (sm[x][j]) {
            if (rev[j] == -1 || try_kuhn(rev[j])) {
                rev[j] = x;
                return true;
            }
        }
    }
    return false;
}

bool
upd_kuhn(int x)
{
    if (used[x]) {
        return false;
    }
    used[x] = true;
    for (int j = 0; j < n; ++j) {
        if (sm[x][j] && j != rev[x]) {
            if (rev[j] == -1 || upd_kuhn(rev[j])) {
                rev[j] = x;
                return true;
            }
        }
    }
    return false;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    gen_primes();
    cin >> n;
    int odd = 0, even = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] % 2 == 0) {
            odd++;
        } else {
            even++;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 == 1) {
            continue;
        }
        for (int j = 0; j < n; ++j) {
            if (is_prime[arr[i] + arr[j]]) {
                sm[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        rev[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 == 1) {
            continue;
        }
        memset(used, 0, sizeof(used[0]) * n);
        try_kuhn(i);
    }
    bool ok = true;
    for (int i = 0; i < n && ok; ++i) {
        if (arr[i] % 2 == 1 && rev[i] == -1) {
            ok = false;
        } else if (arr[i] % 2 == 1) {
            rev[rev[i]] = i;
        }
    }
    if (ok && odd == even) {
        for (int i = 0; i < n && ok; ++i) {
            if (arr[i] % 2 == 0) {
                continue;
            }
            int start = rev[i];
            if (rev[start] != i) {
                continue;
            }
            memset(used, 0, sizeof(used[0]) * n);
            rev[i] = -1;
            sm[start][i] = 0;
            if (!upd_kuhn(start)) {
                ok = false;
            }
            sm[start][i] = 1;
        }
        if (!ok) {
            cout << "Impossible\n";
        } else {
            vector< vi > res;
            memset(used, 0, sizeof(used[0]) * n);
            for (int i = 0; i < n; ++i) {
                if (!used[i]) {
                    vector< int > tmp;
                    int cur = i;
                    while (!used[cur]) {
                        used[cur] = 1;
                        tmp.push_back(cur);
                        cur = rev[cur];
                    }
                    res.push_back(tmp);
                }
            }
            cout << res.size() << '\n';
            for (auto &tmp : res) {
                cout << tmp.size();
                for (auto x : tmp) {
                    cout << " " << x + 1;
                }
                cout << '\n';
            }
        }
    } else {
        cout << "Impossible\n";
    }
    return 0;
}