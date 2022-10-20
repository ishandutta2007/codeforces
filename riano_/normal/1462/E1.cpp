#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;
#define double long double

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
            ll a; cin >> a;
            cnt[a]++;
        }
        ll ans = 0;
        rep(i,N-1){
            ll cc = cnt[i] + cnt[i+1] + cnt[i+2];
            ans += cc*(cc-1)/2*(cc-2)/3;
        }
        rep(i,N-2){
            ll cc = cnt[i+1] + cnt[i+2];
            ans -= cc*(cc-1)/2*(cc-2)/3;
        }
        cout << ans << endl;
    }
    //cout << ans << endl;
}