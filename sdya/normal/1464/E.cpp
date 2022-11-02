#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

const long long P = 998244353LL;

long long inv(long long a) {
    long long x1 = 1, b1 = a;
    long long x2 = 0, b2 = P;
    while (b2) {
        long long q = b1 / b2;
        b1 -= q * b2;
        x1 -= q * x2;
        swap(b1, b2);
        swap(x1, x2);
    }
    return ((x1 % P) + P) % P;
}

long long powmod(long long a, long long n) {
    if (n == 0) {
        return 1;
    }
    long long b = powmod(a, n / 2);
    b = (b * b) % P;
    if (n % 2 == 0) {
        return b;
    }
    return (a * b) % P;
}

const int maxN = 110000;
vector < int > g[maxN];
bool used[maxN];
vector < int > order;
int d[maxN];

int mexx(vector < int > a) {
    set < int > s;
    for (int i = 0; i < a.size(); ++i) {
        s.insert(a[i]);
    }

    for (int i = 0; ; ++i) {
        if (!s.count(i)) {
            return i;
        }
    }
    return -1;
}

void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < g[v].size(); ++i) {
        if (!used[g[v][i]]) {
            dfs(g[v][i]);
        }
    }
    order.push_back(v);
}

long long gauss(vector < vector < long long > >& a, vector < long long > &b) {
    for (int i = 0; i < a.size(); ++i) {
        int index = -1;
        for (int j = 0; j < a[i].size(); ++j) {
            if (a[i][j] != 0) {
                index = j;
                break;
            }
        }
        if (index == -1) {
            continue;
        }

        long long invc = inv(a[i][index]);
        for (int j = 0; j < a[i].size(); ++j) {
            a[i][j] = (a[i][j] * invc) % P;
        }
        b[i] = (b[i] * invc) % P;

        for (int j = 0; j < a.size(); ++j) {
            if (j == i) {
                continue;
            }
            if (a[j][index] != 0) {
                long long coef = (a[j][index]) % P;
                for (int k = 0; k < a[j].size(); ++k) {
                    a[j][k] -= a[i][k] * coef;
                    a[j][k] %= P;
                    if (a[j][k] < 0) {
                        a[j][k] += P;
                    }
                }
                b[j] -= b[i] * coef;
                b[j] %= P;
                if (b[j] < 0) {
                    b[j] += P;
                }
            }
        }
    }
    return b[0];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        g[x].push_back(y);
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    for (int i = 0; i < order.size(); ++i) {
        vector < int > c;
        for (auto& v : g[order[i]]) {
            c.push_back(d[v]);
        }
        d[order[i]] = mexx(c);
    }

    int q = 0;
    for (int i = 0; i < n; ++i) {
        q = max(q, d[i]);
    }

    long long b = 1;
    while (b <= q) {
        b += b;
    }

    vector < int > cnt(b);
    for (int i = 0; i < n; ++i) {
        ++cnt[d[i]];
    }

    long long invn = inv(n + 1);

    vector < vector < long long > > a(b, vector < long long >(b, 0));
    vector < long long > v(b);
    for (int i = 0; i < b; ++i) {
        a[i][i] = (P - 1);
        for (int j = 0; j < b; ++j) {
            long long u = (i ^ j);
            long long p = (invn * (long long)(cnt[j])) % P;
            a[i][u] = (a[i][u] + p) % P;
        }
        v[i] = (i != 0 ? (P - invn) : 0);
        v[i] %= P;
    }
    
    printf("%d\n", (int)(gauss(a, v)));


    return 0;
}