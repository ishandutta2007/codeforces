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
        ll n,x; cin >> n >> x;
        if(n<=2){
            cout << 1 << "\n";
        }
        else{
            cout << (n-3)/x +2 << "\n";
        }
    }
    
    //cout << ans << endl;
}