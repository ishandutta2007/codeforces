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
    double k,d,t; cin >> k >> d >> t;
    double u = ceil((k)/d);
    double en = k+(double)(d*u-k)/2;
    double s = floor(t/en);
    double rem = t-(double)s*en;
    double ans = s*u*d;
    if(rem<=k) ans += rem;
    else{
        ans += k + (rem-k)*2;
    }
    cout << setprecision(18) << ans << endl;
}