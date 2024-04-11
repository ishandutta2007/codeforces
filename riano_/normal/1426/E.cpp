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
    //ll ans = 0;
    ll N; cin >> N;
    ll a[3],b[3];
    rep(i,3) cin >> a[i];
    rep(i,3) cin >> b[(i+2)%3];
    ll mx = 0,mm = 0;
    rep(i,3) mx += min(a[i],b[i]);
    rep(i,3) mm = max(mm,a[i]+b[i]-N);
    cout << mm << " " << mx << endl;
    //cout << ans << endl;
}