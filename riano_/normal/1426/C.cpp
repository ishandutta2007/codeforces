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
        ll ans= 2e9;
        ll k = floor(sqrt((double)N));
        rep(i,100){
            ll s = k-50+i;
            if(s<2||s>N) continue;
            ll c = (N+s-1)/s + s -2;
            //cout << c << endl;
            //if(c==2) cout << s << endl;
            ans = min(ans,c);
        }
        ans = min(ans,N-1);
        cout << ans << "\n";
    }
    //cout << ans << endl;
}