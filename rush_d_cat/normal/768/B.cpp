#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
map<LL, pair<LL,LL> > mp;
pair<LL,LL> getLen(LL n) {
	if (mp.count(n)) return mp[n];
	if (n <= 1) return make_pair(1,n%2);
	pair<LL, LL> p = getLen(n/2);
	return make_pair(2*p.first+1, 2*p.second + n%2);
}
LL cac(LL n, LL x) {
	if (n <= 1) return x==0?0:n;
	LL t = n / 2;
	pair<LL,LL> L = getLen(t);
	if (L.first >= x) {
		return cac(t, x);
	}
	if (L.first + 1 == x) {
		return cac(t, x) + n % 2;
	}
	return L.second + n % 2 + cac(n / 2, x - (L.first + 1));
}
int main() {
	LL l,r; cin>>n>>l>>r;
	cout << cac(n,r) - cac(n,l-1) << endl;
}