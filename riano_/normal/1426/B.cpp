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
        ll N,m; cin >> N >> m;
        ll a[N][4];
        rep(i,N){
            rep(j,4) cin >> a[i][j];
        }
        string ans  ="YES";
        if(m%2!=0) ans = "NO";
        bool key = false;
        rep(i,N){
            if(a[i][1]==a[i][2]) key = true;
        }
        if(!key) ans = "NO";
        cout << ans << "\n";
    }
    
    //cout << ans << endl;
}