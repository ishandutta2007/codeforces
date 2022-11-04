#include <bits/stdc++.h>
using namespace std;

#define MX 200005
typedef long long LL;
LL a[MX];
int n;

int main () {
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int Tc; cin >> Tc;
	while(Tc--) {
		cin >> n;
		cout << n << endl;
		for(int i = 1; i <= n; i++) cout << i << ' '; cout << endl; 
		for(int i = 1; i < n; i++) {
			for(int j = 1; j <= n; j++){
				if(j <= i) cout << j + 1 << ' ';
				else if(j == i + 1) cout << 1 << ' ';
				else cout << j << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}