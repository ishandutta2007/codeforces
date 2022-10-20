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
        ll K;  K = 2;
        string S; cin >> S; ll N = S.size();
        ll cnt[26];
        vector<Pr> cand;
        ll col[N];
        rep(i,N) col[i] = 0;
        rep(i,26){
            cnt[i] = 0;
        }
        rep(i,N){
            ll a = (ll)(S[i]-'a'); cnt[a]++;
            if(cnt[a]<=K){
                cand.push_back(make_pair(a,i));
            }
        }
        sort(cand.begin(),cand.end());
        ll s = cand.size()/K;
        cout << s << endl;
    }
    //cout << ans << endl;
}