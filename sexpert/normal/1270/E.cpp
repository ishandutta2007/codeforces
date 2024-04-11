#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

int main() {
    int n;
    cin >> n;
    vector<ii> v(n);
vector<ll> a, b;
    for(auto &x : v) cin >> x.first >> x.second;
while(true){
a.clear(); b.clear();
for(int i = 0; i < n; i++){
if(abs(v[i].first) % 2 == abs(v[i].second) % 2)
a.push_back(i + 1);
else
b.push_back(i + 1);
}
if(a.size() > 0 && a.size() < n) {
cout << a.size() << '\n';
for(auto x : a)
cout << x << " ";
cout << '\n';
return 0;
}
for(auto &p : v) {
ll x = p.first + p.second, y = p.first - p.second;
if(x % 2) { x++; y++; }
assert((x%2) + (y%2) == 0);
x /= 2; y /= 2;
p = {x, y};
//cout << x << " " << y << endl;
}
}
}