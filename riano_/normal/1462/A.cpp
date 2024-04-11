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
        ll b[K];
        rep(i,K){
            cin >> b[i];
        }
        rep(i,K){
            if(i%2==0) cout << b[i/2] << " ";
            else cout << b[K-1-i/2] << " ";
        }
        cout << endl;
    }
    //cout << ans << endl;
}