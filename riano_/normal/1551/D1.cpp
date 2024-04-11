#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;

const ll mod = 998244353;

int main() {
    ll T; cin >> T;
    rep(iii,T){
        ll N,M,K; cin >> N >> M >> K;
        ll st;
        if(N%2==0) st = 0;
        else{
            st = (N*M)/2;
        }
        string ans = "Yes";
        if(abs(st-K)%2!=0) ans = "No";
        ll sb = (N/2)*(M/2)*2;
        if(st==0){
            if(sb<K) ans = "No";
        }
        else{
            if((st-sb)>K)  ans = "No";
        }
        
        cout << ans << endl;
    }
    //cout << ans << endl;
}