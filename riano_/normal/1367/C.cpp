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
        int N,K; cin >> N >> K;
        string S; cin >> S;
        string st;
        st += "1";
        rep(i,K) st += "0";
        S = st + S;
        reverse(st.begin(),st.end());
        S += st;
        vector<ll> len; int cn = 0;
        rep(i,S.size()){
            if(S[i]=='1'){
                len.push_back(cn); cn = 0;
            }
            else cn++;
        }
        ll ans = 0;
        for(ll x:len){
            ans += max(0LL,(x-2*K+K)/(K+1));
        }
        cout << ans << "\n";
    }
    
}