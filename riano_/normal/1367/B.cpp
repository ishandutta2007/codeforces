#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<int,int,int>
using Graph = vector<vector<int>>;

const ll mod = 1000000007;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll T; cin >> T;
    rep(ii,T){
        int N; cin >> N;
        ll oe = 0,eo = 0;
        rep(i,N){
            ll a; cin >> a;
            if(i%2==0&&a%2==1) eo++;
            if(i%2==1&&a%2==0) oe++;
        }
        ll ans = eo;
        if(eo!=oe) ans = -1;
        cout << ans << "\n";
    }
    
}