#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;

ll mod = 998244353;

int main() {
    ll N; cin >> N;
    rep(i,N){
        ll T; cin >> T;
        int odd = 0;
        rep(j,2*T){
            ll a; cin >> a;
            if(a%2==1) odd++;
        }
        if(odd==T) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    //cout << ans << endl;
}