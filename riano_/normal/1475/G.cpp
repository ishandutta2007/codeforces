#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;

const ll mod = 1000000007;

int main() {
    ll N; cin >> N;
    Graph G(200001);
    for(int i=1;i<200001;i++){
        for(int j=2*i;j<200001;j+=i){
            G[j].push_back(i);
        }
    }
    rep(ii,N){
        ll n; cin >> n;
        ll cnt[200001],par[200001];
        rep(i,200001){
            cnt[i] = 0; par[i] = 0;
        }
        rep(i,n){
            ll a; cin >> a; cnt[a]++;
        }
        //cout << "------" << endl;
        for(int i=200000;i>=0;i--){
            ll sc = par[i]+cnt[i];
            for(ll x:G[i]){
                par[x] = max(sc,par[x]);
            }
        }
        ll ans = 0;
        rep(i,200001){
            ans = max(ans,cnt[i]+par[i]);
        }
        cout << n-ans << endl;
    }
    //cout << ans << endl;
}