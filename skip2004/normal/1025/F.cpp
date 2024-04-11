#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
typedef double db;
const db pi = std::acos(-1);
int n, x[maxn], y[maxn];
inline ll calc(ll x) { return x * (x - 1) >> 1; } 
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0;i < n;++i) {
		cin >> x[i] >> y[i];
	}
	ll ans = 0;
	for(int i = 0;i < n;++i) {
		std::vector<db> vc; vc.reserve(n - 1);
		for(int j = 0;j < n;++j) if(i != j) {
			vc.push_back(atan2(y[j] - y[i], x[j] - x[i]));
		}
		sort(vc.begin(), vc.end());
		for(int i0 = 0, i1 = 0;i0 < vc.size() && vc[i0] <= 0;++i0) {
			for(;i1 < vc.size() && vc[i1] <= vc[i0] + pi;) ++ i1;
			const int cnt = i1 - i0 - 1;
			ans += calc(cnt) * calc(n - 2 - cnt);
		}
	}
	cout << ans << '\n';
}