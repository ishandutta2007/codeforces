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

#define MN 23
int n, m;
int a[1<<MN];
//vi e[1<<MN];
int ret[1<<MN];
int vis[1<<MN];
void dfs(int cn){
    if(vis[cn]) return;
    vis[cn] = true;
    /*for(auto nn : e[cn]){
        dfs(nn);
    }*/
    if(ret[cn] != -1){
        //cout << cn << " " << ret[cn] << "\n";
        dfs(ret[cn]);
    }
    if(cn >= (1<<n)){
        //dfs(cn-(1<<n));
        //cout << cn << " " << a[cn] << "\n";
        dfs(a[cn]);
    } else{
        F0R(i, n){
            if((cn & (1<<i)) == 0){
                //cout << cn << " " << (cn | (1<<i)) << "\n";
                dfs(cn | (1<<i));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(ret, -1, sizeof ret);

    cin >> n >> m;
    /*F0R(i, 1<<n){
        F0R(j, n){
            if(i & (1<<j)){
                int o = i ^ (1<<j);
                e[o].pb(i);
                //cout << o << " " << i << "\n";
            }
        }
    }*/
    F0R(j, m){
        int v = (1<<n)+j;
        cin >> a[v];
        //e[v].pb(x);
        //cout << v << " " << a[j] << "\n";
        int fl = (1<<n)-1;
        int o = fl ^ a[v];
        //e[o].pb(v);
        ret[o] = v;
        //cout << o << " " << v << "\n";
    }
    int cnt = 0;
    F0R(j, m){
        int v = (1<<n)+j;
        if(!vis[v]){
            ++cnt;
            dfs(v);
        }
    }
    cout << cnt << "\n";

    return 0;
}