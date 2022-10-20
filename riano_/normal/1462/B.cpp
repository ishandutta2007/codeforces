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
    ll N; cin >> N;
    rep(ii,N){
        ll K; cin >> K;
        string S; cin >> S; S += '0';
        string ans = "No";
        rep(i,5){
            string T = S.substr(0,i) + S.substr(K-4+i,4-i);
            if(T=="2020") ans = "Yes";
        }
        cout << ans << endl;
    }
    //cout << ans << endl;
}