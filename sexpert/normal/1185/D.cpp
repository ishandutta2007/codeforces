#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> ii;

int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);

int n;
cin >> n;
vector<ii> v;
for(int i = 0; i < n; i++) {
int x;
cin >> x;
v.push_back({x, i + 1});
}
if(n == 2) {
cout << "1\n";
return 0;
}
sort(v.begin(), v.end());
//try first
ll diff = v[n - 1].first - v[1].first;
if(diff % (n - 2) == 0) {
diff /= (n - 2);
for(int i = 1; i < n; i++) {
if(v[i].first != v[1].first + diff*(i - 1))
break;
if(i == n - 1) {
cout << v[0].second << '\n';
return 0;
}
}
}
// try end
diff = v[n - 2].first - v[0].first;
if(diff % (n - 2) == 0) {
diff /= (n - 2);
for(int i = 0; i < n - 1; i++) {
if(v[i].first != v[0].first + diff*i)
break;
if(i == n - 2) {
cout << v[n - 1].second << '\n';
return 0;
}
}
}
// try mid
diff = v[n - 1].first - v[0].first;
if(diff % (n - 2)) {
cout << "-1\n";
return 0;
}
diff /= (n - 2);
int bad = -1;
set<int> seen;
for(int i = 0; i < n; i++) {
int a = v[i].first;
if((a - v[0].first)%diff) {
if(bad != -1) {
cout << "-1\n";
return 0;
}
bad = v[i].second;
}
if(seen.count(a)) {
if(bad != -1) {
cout << "-1\n";
return 0;
}
bad = v[i].second;
}
seen.insert(a);
}
cout << bad << '\n';
}