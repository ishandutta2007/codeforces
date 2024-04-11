#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 1e5 + 100;
const ll P = 997;

string hs[MAXN];
set<string> paths[MAXN];

ll sethash(const set<string> & st) {
    ll pw = 1;
    ll res = 0;
    for (auto s : st) {
        forn(i, s.length()) {
            res += pw * s[i];
            pw *= P;
        }
        res += pw * '$';
        pw *= P;
    }
    return res;
}



int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    //freopen("", "w", stderr);
#endif
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    int hosts = 0;
    map<string, int> hnum;
    forn(i, n) {
        string s;
        cin >> s;
        int f= s.find('/', 7);
        if (f == string::npos) {
            f = s.length();
        }
        string host = s.substr(0, f);
        string path = s.substr(f);
//        cerr << host << ' ' << path << '\n';
        if (hnum.count(host) == 0) {
            hs[hosts] = host;
            hnum[host] = hosts++;
        }
        int nm = hnum[host];
        paths[nm].insert(path);
    }
    map<ll, vector<int>> groups;
    forn(i, hosts) {
        ll h = sethash(paths[i]);
        if (groups.count(h) == 0) {
            groups[h] = vector<int>();
        }
        groups[h].pb(i);
    }
    int ans = 0;
    for (auto it : groups) {
        if (it.second.size() > 1) {
            ans++;
        }
    }
    cout << ans << '\n';
    for (auto it : groups) {
        if (it.second.size() > 1) {
            for (auto i : it.second) {
                cout << hs[i] << ' ';
            }
            cout << '\n';
        }
    }
    

    
    return 0;
}