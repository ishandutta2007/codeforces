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
 
#define MN 500005
int t;
int n, m;
ll c[MN];
 
int bs;
ll exps[MN];
 
ll hsh[MN];
map<ll, ll> ree;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 bruh(seed1);
    bs = 100+bruh()%100;
    exps[0] = 1;
    FOR(i, 1, MN-1){
        exps[i] = (exps[i-1]*bs)%MOD;
    }
 
    cin >> t;
    F0R(_, t){
        cin >> n >> m;
        FOR(i, 1, n) cin >> c[i];
        F0R(_, m){
            int u, v;
            cin >> u >> v;
            hsh[v] += exps[u];
            hsh[v] %= MOD;
        }
        FOR(i, 1, n){
            //cout << i << " " << hsh[i] << "\n";
            if(hsh[i] != 0) ree[hsh[i]] += c[i];
        }
        if(ree.empty()){
            cout << "0\n";
        } else{
            ll gcd = ree.begin()->s;
            for(auto u : ree){
                //cout << u.s << " ";
                gcd = __gcd(gcd, u.s);
            }
            
            //cout << "\n";
            cout << gcd << "\n";
        }
 
        ree.clear();
        FOR(i, 1, n) hsh[i] = 0;
    }
 
    return 0;
}