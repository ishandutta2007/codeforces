#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int inf = (int)1E+9;

typedef long long int64;
typedef pair<int,int> pii;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) a.begin(), a.end()
#define last(a) (int)a.size() - 1
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())

#define sqr(a) (a)*(a)

const string task = "a";
const string inp = task + ".in";
const string outp = task + ".out";

const int nmax = 24;

pii s;
pii a[nmax];
int n;
int t[1 << nmax];
pii p[1 << nmax];

int calc(pii a, pii b){
    return sqr(a.x-b.x)+sqr(a.y-b.y);
}

inline void go(int &a, int b, pii e, pii &w){
    if (a == -1 || a > b){
        a = b;
        w = e;
    }
}

int main(){
//  freopen(inp.data(), "rt", stdin);
//  freopen(outp.data(),"wt", stdout);

    cin >> s.x >> s.y >> n;
    forn(i,n)
        cin >> a[i].x >> a[i].y;
    memset(t,255,sizeof t);
    t[0] = 0;
    forn(i,1 << n)
        if (t[i] >= 0){
            int j = 0;
            while (i & (1 << j)) j ++;
            if (j >= n) break;
            go(t[i | (1 << j)],t[i] + calc(a[j],s)*2,mp(j,-1),p[i | (1 << j)]);
            for (int k = j + 1; k < n; k++)
                if (!(i & (1 << k)))
                    go(t[i | (1 << j) | (1 << k)], t[i] + calc(s,a[j]) + calc(a[j],a[k]) + calc(a[k],s), mp(k,j),p[i | (1 << j) | (1 << k)]);
        }
    cout << t[(1 << n) -1] << endl;
    int now =            (1 << n) -1;
    vector<int> res;
    res.pb(0);
    while (now > 0){
        pii e = p[now];
        if (e.y != -1){
            now -= 1 << e.y;
            res.pb(e.y+1);
        }
        now -= 1 << e.x;
        res.pb(e.x+1);
        res.pb(0);
    }
    ford(i,res.size())
        cout << res[i] << " ";
    cout << endl;
    return 0;
}