#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 100005
int t;
int n;
pair<pii, int> trips[MN];
set<pii> on;
void tog(pii a){
    if(a.f > a.s) swap(a.f, a.s);
    if(on.count(a)) on.erase(a);
    else on.insert(a);
}
vi e[MN];
int ord[MN];
int inv[MN];
int tim;
void go(int cn, int p, int o){
    ord[tim] = cn;
    inv[cn] = tim;
    ++tim;
    if(e[cn][0] == p){
        if(e[cn][1] == o) return;
        go(e[cn][1], cn, o);
    } else{
        if(e[cn][0] == o) return;
        go(e[cn][0], cn, o);
    }
}
 
pii vals[MN];
int cd(int x, int y, int z){
    if(x > y) swap(x, y);
    if(x > z) swap(x, z);
    if(y > z) swap(y, z);
    int d1 = y-x, d2 = z-y, d3 = x+n-z;
    if(d1 >= d2 && d1 >= d3){
        return d1;
    } else if(d2 >= d1 && d2 >= d3){
        return d2;
    } else{
        return d3;
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> t;
    F0R(_, t){
        cin >> n;
        F0R(i, n-2){
            cin >> trips[i].f.f >> trips[i].f.s >> trips[i].s;
            tog({trips[i].f.f, trips[i].f.s});
            tog({trips[i].f.f, trips[i].s});
            tog({trips[i].f.s, trips[i].s});
        }
        for(auto u : on){
            e[u.f].pb(u.s);
            e[u.s].pb(u.f);
        }
        tim = 0;
        go(1, e[1][0], 1);
        F0R(i, n){
            cout << ord[i] << " ";
        }
        cout << "\n";
        F0R(i, n-2){
            int a = trips[i].f.f, b=trips[i].f.s, c=trips[i].s;
            vals[i] = {cd(inv[a], inv[b], inv[c]), i};
            //cout << a << " " << b << " " << c << " " << vals[i].f << " " << vals[i].s << "\n";
        }
        sort(vals, vals+n-2, greater<pii>() );
        F0R(i, n-2){
            cout << vals[i].s+1 << " ";
        }
        cout << "\n";
 
        on.clear();
        FOR(i, 1, n) e[i].clear();
    }
    
    return 0;
}