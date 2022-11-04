#include <bits/stdc++.h>
#define MX 300005
using namespace std;

int T;
int n, a[MX];
int P[MX], C[MX];

int main() {
//	freopen("in.txt", "r", stdin);
	int i;
	cin >> T;
//	cout << T << '\n';
	while(T --) {
		cin >> n;
		C[0] = MX;
		for(i = 1; i <= n; i ++) {
			cin >> a[i];
			if(a[i] < C[i - 1]) C[i] = a[i], P[i] = i;
			else C[i] = C[i - 1], P[i] = P[i - 1];
		}
		
//		for(i = 1; i <= n; i ++) cout << i << ' ' << P[i] << '\n';
		
		int nn = n - 1, tp = a[n];
		while(nn) {
//			cout << nn << '\n';
			if(C[nn] > tp) break;
			nn = P[nn] - 1;
		}
		
		if(nn > 0) cout << "NO\n";
		else cout << "YES\n";
	}
}