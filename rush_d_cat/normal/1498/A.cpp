#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
LL gcd(LL x, LL y) {
	return y == 0 ? x : gcd(y, x%y);
}
LL sum(LL x) {
	LL ans = 0;
	while (x) {
		ans += x%10; x/=10;
	}
	return ans;
}
LL cal(LL x) {
	while (gcd(x, sum(x)) == 1) ++ x;
	return x;
}
int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t --){
		LL x; cin >> x;
		cout << cal(x) << endl;
    }
}