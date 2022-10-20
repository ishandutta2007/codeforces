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
        ll a[N],b[N]; ll ma = 2e9,mb = 2e9;
        rep(i,N){
            cin >> a[i]; ma = min(ma,a[i]);
        }
        rep(i,N){
            cin >> b[i]; mb = min(mb,b[i]);
        }
        ll ans = 0;
        rep(i,N){
            ans += max(a[i]-ma,b[i]-mb);
        }
        cout << ans << endl;
    }
    
    //cout << ans << endl;
}