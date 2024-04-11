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
 
#define MN 200005
int n, m;
vi e[MN];
int d[MN];
bool two[MN];
int k;
vi pth;
 
queue<int> q;
void bfs(){
    memset(d, 0x3f, sizeof d);
    d[pth[k-1]] = 0;
    q.push(pth[k-1]);
 
    while(!q.empty()){
        int cn = q.front();
        q.pop();
        for(auto nn : e[cn]){
            if(d[nn] == d[cn]+1){
                two[nn] = true;
                //cout << nn << " has two\n";
            } else if(d[nn] == INF){
                d[nn] = d[cn]+1;
                //cout << "dist to " << nn << " " << cn << "\n";
                q.push(nn);
            }
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> m;
    F0R(_, m){
        int u, v;
        cin >> u >> v;
        //e[u].pb(v);
        e[v].pb(u); //reverse graph
    }
    cin >> k;
    F0R(_, k){
        int x;
        cin >> x;
        pth.pb(x);
    }
    bfs();
    int mn = 0; int mx = 0;
    F0R(i, k-1){
        int cn = pth[i]; int nn = pth[i+1];
        if(d[cn] != d[nn]+1){
            ++mn;
            ++mx;
        }
        if(d[cn] == d[nn]+1 && two[cn]){
            ++mx;
        }
    }
    cout << mn << " " << mx << "\n";
 
    return 0;
}