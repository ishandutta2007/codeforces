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
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
#define MK 105
int n, m, k, s;
int a[MN];
vi e[MN];
int d[MN][MK];

void bfs(int x){
    queue<int> ree;
    FOR(i, 1, n){
        if(a[i] == x){
            d[i][x] = 0;
            ree.push(i);
        }
    }
    while(!ree.empty()){
        int cn = ree.front();
        ree.pop();
        for(auto nn : e[cn]){
            if(d[nn][x] == INF){
                d[nn][x] = d[cn][x]+1;
                ree.push(nn);
            }
        }
    }
    /*FOR(i, 1, n){
        cout << d[i][x] << " ";
    }
    cout << "\n";*/
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(d, 0x3f, sizeof d);

    cin >> n >> m >> k >> s;
    FOR(i, 1, n){
        cin >> a[i];
    }
    F0R(_, m){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }

    FOR(i, 1, k){
        bfs(i);
    }

    FOR(i, 1, n){
        sort(d[i]+1, d[i]+k+1);
        int sm = 0;
        FOR(j, 1, s){
            sm += d[i][j];
        }
        cout << sm << " ";
    }

    return 0;
}