#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
signed main() {
	int q;
	cin >> q;
	while (q) {
		q--;
		int a, b, m;
		cin>>a>>b>>m;
		if (a == b) {
			cout<<1<<" "<<a<<endl;
			continue;
		}
		if (a > b) {
			cout << -1 << endl;
			continue;
		}
		int n = 0;
		while (n <= 49) {
			n++;
			int l = (1ll << (n - 1)) * (a + 1), r = (1ll << (n - 1)) * (a + m);
			if (l > b) {
				n = 51;
				break;
			}
			if (b <= r && b >= l)
				break;
		}
		if (n >= 50) {
			cout << -1 << endl;
			continue;
		}
		cout<<n+1<<" "<<a<<endl;
		int tot = 0, sum = a;
		for (register int i = 1; i < n; i++) {
			int r = min((b - (1ll << (n - 1)) - (1ll << (n - 1)) * a - tot) / (1ll << (n - i - 1)), m - 1);
			tot += (1ll << (n - i - 1)) * r;
			cout<<sum+r+1<<" ";
			sum += sum;
			sum += r + 1;
		}
		cout<<b<<endl;
	}
	return 0;
}