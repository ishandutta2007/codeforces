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
    ll ans = 0;
    ll N; cin >> N;
    ll a[N];
    rep(i,N) cin >> a[i];
    set<ll> app;
    app.insert(0);
    ll sum = 0;
    rep(i,N){
        sum += a[i];
        if(app.count(sum)){
            ans++;
            app.clear();
            app.insert(sum-a[i]);
            app.insert(sum);
        }
        else{
            app.insert(sum);
        }
    }
    cout << ans << endl;
}