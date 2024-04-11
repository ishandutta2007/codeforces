#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll f(ll x) {
return x*(x-1)*(x-2)/6ll;
}

int main() {
int n;
cin >> n;
vector<P> ps;
for(int i = 0; i < n; i++) {
ll x, y;
cin >> x >> y;
ps.push_back({x, y});
}
map<pair<P, ll>, set<P>> cnt;
for(int i = 0; i < n; i++){
for(int j = i + 1; j < n; j++){
ll dx = ps[i].first-ps[j].first, dy = ps[i].second-ps[j].second, d = __gcd(abs(dx), abs(dy));
dx /= d; dy /= d;
if(dx < 0 || (dx == 0 && dy <0)){dx*=-1; dy*=-1;}
cnt[{{dx, dy}, ps[i].first*(-dy) + ps[i].second*dx}].insert(ps[i]);
cnt[{{dx, dy}, ps[i].first*(-dy) + ps[i].second*dx}].insert(ps[j]);
}
}
ll ans=f(n);
for(auto p : cnt)
ans -= f(p.second.size());
cout << ans << endl;
}