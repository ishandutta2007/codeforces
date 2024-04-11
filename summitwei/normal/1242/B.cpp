#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
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
int n, m;
vi e[MN];
int dsu[MN];
int sz[MN];
int fd(int x){
    if(dsu[x] == x) return x;
    dsu[x] = fd(dsu[x]);
    return dsu[x];
}
int tow[MN];
set<int> good;
vi bad;
void jn(int x, int y){
    //cout << "merging " << x << " " << y << "\n";
    x = fd(x); y = fd(y);
    if(x == y) return;
    if(sz[x] < sz[y]) swap(x, y);
    dsu[y] = x;
    sz[x] += sz[y];
    bad.pb(y);
    //cout << "done! deleted " << y << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> m;
    F0R(_, m){
        int a, b;
        cin >> a >> b;
        e[a].pb(b);
        e[b].pb(a);
    }
    FOR(i, 1, n){
        dsu[i] = i;
        sz[i] = 1;
    }
    FOR(i, 1, n){
        //cout << "doing " << i << "\n";
        good.insert(i);
        for(auto u : e[i]){
            if(u > i) continue;
            ++tow[fd(u)];
        }
        for(auto u : good){
            if(u == i) continue;
            if(tow[u] != sz[u]){
                jn(i, u);
            }
            tow[u] = 0;
        }
        for(auto u : bad){
            good.erase(u);
        }
        bad.clear();
    }
    cout << good.size()-1 << "\n";

    return 0;
}