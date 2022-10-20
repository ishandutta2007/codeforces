#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;

const ll mod = 1000000007;

int main() {
    ll N; cin >> N;
    rep(i,N){
        ll a; cin >> a;
        ll c = a/2020;
        a -= 2020*c;
        if(a<=c){
            cout << "YES" << endl;
        }
        else{
            cout <<"NO" << endl;
        }
    }
    //cout << ans << endl;
}