#include<bits/stdc++.h>
using std::cin;
using std::cout;
using ll = long long;
int t;
const int N = 100005;
int a[N], b[N];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> t;
	for(int i = 0;i < t;++i) {
		int n;
		cin >> n;
		for(int i = 1;i <= n;++i) cin >> a[i];
		std::vector<int> A, B;
		ll ans = 0;
		for(int i = 1, x;i <= n;++i) {
			cin >> x;
			ans += x;
			(a[i] ? A : B).push_back(x);
		}
		if(A.size() > B.size()) {
			std::swap(A, B);
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		if(A.size() < B.size()) {
			for(int i : A) ans += i;
			for(int i = 0;i < (int) A.size();++i) {
				ans += B[B.size() - 1 - i];
			}
		} else {
			ans *= 2;
			ans -= std::min(A[0], B[0]);
		}
		cout << ans << '\n';
	}
}