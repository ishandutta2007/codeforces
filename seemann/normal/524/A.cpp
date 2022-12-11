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

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const int MAXN = 301;

int a[MAXN][2];
map<int, int> mp;
int e[MAXN][MAXN];
vector<int> ans[MAXN];

int main() {
//	freopen("a.in", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
    int m, k;
    cin >> m >> k;
    set<int> p;
    FOR(i, m) {
        cin >> a[i][0] >> a[i][1];
        p.insert(a[i][0]);
        p.insert(a[i][1]);
    }
    vector<int> vp;
    int cnt = 0;
    for (auto i : p) {
        vp.push_back(i);
        mp[i] = cnt++;
    }
    FOR(i, m) {
        e[mp[a[i][0]]][mp[a[i][1]]] = 1;
        e[mp[a[i][1]]][mp[a[i][0]]] = 1;
    }
    int n = cnt;
    /*
    FOR(i, n) {
        FOR(j, n) {
        cerr << e[i][j] << ' ';
        }
        cerr << '\n';
    }*/
    FOR(i, n)  {
        int cf = 0;
        FOR(j, n) {
           
            if (i == j)
                continue;
            if (e[i][j] == 1)
                cf++;
        }
        FOR(j, n) {
            if (i == j)
                continue;
            if (e[i][j] == 1) {
                continue;
            }
            int nm = 0;
            FOR(k, n) {
                if (k == i || k == j)
                    continue;
                if (e[k][i] == 1 && e[k][j] == 1)
                    nm++;
            }
       //     cerr << vp[i] << ' ' << vp[j] << ' ' << nm << ' ' << cf << '\n';
            if (100 * nm >= k * cf) {
                ans[i].push_back(j);
            }
        }
    }
    FOR(i, n) {
        int nm = vp[i];
        cout << nm << ": ";
        cout << ans[i].size() << ' ';
        FOR(j, ans[i].size()) {
            cout << vp[ans[i][j]] << ' ';
        }
        cout << '\n';
    }
    
	return 0;
}