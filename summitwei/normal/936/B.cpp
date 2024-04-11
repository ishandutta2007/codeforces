#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef long double ld;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n, m;
vi e[MN]; //
int s[MN];

int vis[MN];
vi ree;
int dfs(int cn){
    //cout << "on " << cn << "\n";
    if(vis[cn] == 2) return 0;
    if(vis[cn] == 1) return 1;
    vis[cn] = 1;
    //ree.pb(cn);
    if(e[cn].empty()){
        if(cn % 2 == 0){vis[cn] = 2; return 0;}
        else{ree.pb(cn); return 2;}
    }
    ree.pb(cn);
    int stat = 0;
    for(auto nn : e[cn]){
        stat = max(stat, dfs(nn));
        if(stat == 2) return 2;
    }
    ree.pop_back();
    vis[cn] = 2;
    return stat;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 1, n){
        int x;
        cin >> x;
        F0R(_, x){
            int v;
            cin >> v;
            e[i*2-1].pb(v*2);
            e[i*2].pb(v*2-1);
        }
    }
    int s;
    cin >> s;
    int res = dfs(s*2);
    if(res == 0){
        cout << "Lose\n";
    } else if(res == 1){
        cout << "Draw\n";
    } else{
        cout << "Win\n";
        for(auto u : ree){
            cout << (u+1)/2 << " ";
        }
        cout << "\n";
    }
    
    return 0;
}