#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int BI = 25;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for(auto &x : v)
		cin >> x;
	int ans = 0;
	for(int b = BI - 1; b >= 0; b--) {
		//cout << "BIT " << b << endl;
		vector<int> tmp;
		int res = 0;
		for(int i = 0; i < n; i++) {
			res ^= (((v[i] >> b) & 1) * ((n + 1) & 1));
			tmp.push_back(v[i] & ((1 << b) - 1));
		}
		sort(tmp.begin(), tmp.end());
		//for(auto x : tmp)
		//	cout << x << " ";
		//cout << endl;
		if(b == 0) {
			ans += res;
			break;
		}
		//cout << "res = " << res << endl;
		int l = 0, r = n - 1;
		while(l < n) {
			//cout << " " << l << ", " << r << endl;
			while(r <= l)
				r++;
			if(tmp[l] + tmp[r] < (1 << b)) {
				l++;
				continue;	
			}
			while(r - 1 > l && tmp[l] + tmp[r - 1] >= (1 << b))
				r--;
			int cr = (n - r) & 1;
			res ^= cr;
			l++;
		}
		//cout << "res = " << res << endl;
		ans += (res << b);
	}
	cout << ans << '\n';
}

// 0 1 1