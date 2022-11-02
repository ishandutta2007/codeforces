#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL //119*2^23+1
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n, m;
vi e[MN];
int d[MN];
int x;
vi yeet;
bool yeeted[MN];
int p[MN];
vi ree;

bool dfs(int cn){
    int bc = 0;
    for(auto nn : e[cn]){
        if(d[nn] == -1){
            d[nn] = d[cn]+1;
            p[nn] = cn;
            if(dfs(nn)) return true;
        } else if(nn != p[cn]){
            ++bc;
        }
    }
    //cout << cn << " has " << bc << "\n";
    if(bc >= x-2){
        //cout << "2\n";
        int mn = cn;
        for(auto nn : e[cn]){
            if(d[nn] < d[mn]) mn = nn;
        }
        int cur = cn;
        while(cur != mn){
            //cout << cur << " ";
            ree.pb(cur);
            cur = p[cur];
        }
        //cout << mn << "\n";
        ree.pb(mn);
        return true;
    } else if(!yeeted[cn]){
        yeet.pb(cn);
        for(auto nn : e[cn]){
            yeeted[nn] = true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    while(x*x<n) ++x;
    F0R(_, m){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    memset(d, -1, sizeof d);
    d[1] = 0;
    if(!dfs(1)){
        cout << "1\n";
        F0R(i, x){
            cout << yeet[i] << " ";
        }
        cout << "\n";
    } else{
        cout << "2\n" << ree.size() << "\n";
        for(auto u : ree){
            cout << u << " ";
        }
        cout << "\n";
    }

    return 0;
}