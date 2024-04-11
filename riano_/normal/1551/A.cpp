#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;

const ll mod = 998244353;

int main() {
    ll N; cin >> N;
    rep(i,N){
        ll K; cin >> K;
        ll a = K/3;
        ll c = a; ll d = a;
        if(K%3==1){
            c++;
        }
        if(K%3==2) d++;
        cout << c << " " << d << endl;
    }
    //cout << ans << endl;
}