#include <bits/stdc++.h>
using namespace std;

vector<int> v;

bool check(int i) {
	int msk = (1 << 30) - 1;
	for(auto x : v)
		if(x & (1 << i))
			msk &= x;
	return (((msk>>i)<<i) == msk);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while(n--) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	for(int i = 30; i >= 0; i--) {
		if(check(i)) {
			int cnt = 0;
			for(auto x : v)
				if(x & (1 << i))
					cnt++;
			cout << cnt << '\n';
			for(auto x : v)
				if(x & (1 << i))
					cout << x << " ";
			cout << endl;
			return 0;
		}
	}
}