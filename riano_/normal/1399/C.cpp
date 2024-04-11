#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;

const ll mod = 1000000007;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll T; cin >> T;
    rep(ii,T){
        ll N; cin >> N;
        ll cnt[N+1];
        rep(i,N+1) cnt[i] = 0;
        rep(i,N){
            ll w; cin >> w; cnt[w]++;
        }
        ll ans = 0;
        for(ll i=2;i<=2*N;i++){
            ll pr = 0;
            for(ll j=1;j<=N;j++){
                ll k = i-j;
                if(k<=0||k>N||k>j) continue;
                if(j!=k) pr += min(cnt[j],cnt[k]);
                else pr += cnt[j]/2;
            }
            ans = max(pr,ans);
        }
        cout << ans << "\n";
    }
    
    //cout << ans << endl;
}