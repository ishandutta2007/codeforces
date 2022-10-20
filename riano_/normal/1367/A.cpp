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
        string S; cin >> S;
        string ans; ans += S[0];
        int N = S.size();
        rep(i,N){
            if(i%2==1){
                ans += S[i];
            }
        }
        //ans += S[N-1];
        cout << ans << "\n";
    }
    
}