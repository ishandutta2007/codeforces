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
        vector<ll> a;
        rep(i,N){
            ll b; cin >> b; a.push_back(b);
        }
        sort(a.begin(),a.end());
        string ans = "YES";
        rep(i,N-1){
            if(a[i+1]-a[i]>=2) ans = "NO";
        }
        cout << ans << endl;
    }
    
    //cout << ans << endl;
}