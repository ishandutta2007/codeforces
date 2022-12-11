#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())
#define sqr(a) (a)*(a)

typedef long long int64;
typedef pair<int,int> pii;

const int inf = (int)1E+9;
const double eps = 1e-9;

const string task = "a";
const string inp = task + ".in";
const string oup = task + ".out";

const int nmax = 5010;

long long a[nmax];
long long t[nmax], f[nmax];
int n;
long long res;

int main(){
//  freopen(inp.data(), "rt", stdin);
//  freopen(oup.data(),"wt", stdout);

    cin >> n;
    forn(i,n)
        cin >> a[i];
    long long res = 1e18;
    forn(i,n)
        t[i] = abs(a[i] - a[0]);
    f[1] = 0;
    vector<pii> e;
    forn(i,n)
        e.pb(mp(a[i],i));
    sort(all(e));
    for (int i = 1; i < n; i++){
        long long now = 1e18;
        forn(j,e.size()){
            int p = e[j].sc;
            now = min(now, t[p]);
            t[p] = now + abs(a[i] - a[p]);
        }
    }
    forn(i,n)
        res = min(res,t[i]);
    cout << res << endl;
    return 0;
}