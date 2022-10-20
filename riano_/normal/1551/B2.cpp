#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;

const ll mod = 998244353;

int main() {
    ll T; cin >> T;
    rep(ii,T){
        ll N,K; cin >> N >> K;
        ll cnt[N+1];
        vector<Pr> cand;
        ll col[N];
        rep(i,N) col[i] = 0;
        rep(i,N+1){
            cnt[i] = 0;
        }
        rep(i,N){
            ll a; cin >> a; cnt[a]++;
            if(cnt[a]<=K){
                cand.push_back(make_pair(a,i));
            }
        }
        sort(cand.begin(),cand.end());
        ll s = cand.size()/K;
        rep(i,s*K){
            auto[a,k] = cand[i];
            col[k] = i%K+1;
        }
        rep(i,N){
            cout << col[i] << " ";
        }
        cout << endl;
    }
    //cout << ans << endl;
}