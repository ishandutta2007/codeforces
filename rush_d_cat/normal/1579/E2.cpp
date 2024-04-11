#include <bits/stdc++.h>
using namespace std;
struct Bit {
	vector<int> a;
	Bit(int n) {
		a.resize(n, 0);
	}
	void add(int pos, int x) {
		while (pos < a.size()) {
			a[pos] += x;
			pos += pos & (-pos);
		}
	}
	int sum(int pos) {
		int ans = 0;
		while (pos > 0) {
			ans += a[pos];
			pos -= pos & (-pos);
		}
		return ans;
	}
	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};


int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i=0;i<n;i++)cin>>a[i];
		vector<int> v = a;
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		auto id = [&](int x){
			return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
		};
		Bit B(v.size()+1);
		long long ans = 0;
		for (int i = 0; i < a.size(); i ++) {
			int cnt1 = B.sum(id(a[i]) - 1);
			int cnt2 = B.sum(v.size()) - B.sum(id(a[i]));
			ans += min(cnt1, cnt2);
			B.add(id(a[i]),1);
		}
		cout << ans << "\n";
	}		
}