#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int n, m;
int a[200100];
int d[300], p[300];
vector<int> dv;
vector<int> ok[200100];
bool was[200100];
int in_div[200100];
int phi = 0;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

long long inv(int a) {
    if (a == 0) {
        return 0;
    }
    int p = phi - 1;
    long long sq = a, res = 1;
    while (p > 0) {
        if (p % 2) {
            res *= sq;
            res %= m;
        }
        sq *= sq;
        sq %= m;
        p /= 2;
    }
    return res % m;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    forn (i, m + 1) {
        in_div[i] = -1;
    }
    for (int i = 1; i * i <= m; ++i) {
        if (m % i) {
            continue;
        }
        dv.pb(i);
        if (i * i < m) {
            dv.pb(m / i);
        }
    }
    sort(dv.begin(), dv.end());
    forn (i, dv.size()) {
        in_div[dv[i]] = i;
    }
    forn (i, n) {
        cin >> a[i];
        was[a[i]] = true;
//        ban[in_div[m / gcd(m, a[i])]].pb(a[i]);
    }
    forn (i, m) {
        if (was[i]) {
            continue;
        }
        ok[in_div[m / gcd(i, m)]].pb(i / gcd(i, m));
//        cerr << m / gcd(i, m) << ' ' << i / gcd(i, m) << endl;
    }
    forn (i, dv.size()) {
        d[i] = ok[i].size();
        p[i] = -1;
        int mx = -1, ind = -1;
//        cerr << dv[i] << " " << d[i] << " " << p[i] << endl;
        forn (j, i) {
            if (dv[i] % dv[j]) {
                continue;
            }
            if (mx < d[j]) {
                mx = d[j];
                ind = j;
            }
        }
        d[i] += max(0, mx);
        p[i] = ind;
//        cerr << dv[i] << " " << d[i] << " " << p[i] << endl;
    }
//    cerr << endl;
    int cur = dv.size() - 1;
    int last = 1, trans = 1;
    vector<int> res;
    while (cur != -1) {
//        cerr << dv[cur] << endl;
        forn (i, ok[cur].size()) {
//            cerr << ok[cur][i] << ' ';
            long long ans = ok[cur][i] * inv(last) % m;
            if (i == 0) {
                ans *= trans;
                ans %= m;
                phi = 0;
                forn (j, dv[cur]) {
                    if (gcd(dv[cur], j) == 1) {
                        phi++;
                    }
                }
            }
            last = ok[cur][i];
            res.pb(ans);
        }
//        cerr << endl << endl;
        if (p[cur] != -1) {
            trans = dv[cur] / dv[p[cur]];
        }
        cur = p[cur];
    }
    cout << res.size() << endl;
    forn (i, res.size()) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}