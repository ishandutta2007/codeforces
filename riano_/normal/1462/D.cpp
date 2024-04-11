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
        ll a[K]; ll sum = 0;
        rep(i,K){
            cin >> a[i]; sum += a[i];
        }
        vector<ll> cand;
        for(ll i=1;i*i<=sum;i++){
            if(sum%i==0){
                cand.push_back(i);
                cand.push_back(sum/i);
            }
        }
        sort(cand.begin(),cand.end());
        for(ll x:cand){
            ll now = 0;
            bool ok = true;
            rep(i,K){
                now += a[i];
                if(now>x){
                    ok = false; break;
                }
                else if(now==x) now -= x;
            }
            if(ok){
                cout << K-sum/x << endl; break;
            }
        }
    }
    //cout << ans << endl;
}