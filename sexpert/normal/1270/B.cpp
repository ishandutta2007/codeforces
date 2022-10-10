#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 2e5 + 10;
int a[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++)
		cin >> a[i];
		bool b = false;
		for(int i = 1; i < n; i++) {
			if(abs(a[i] - a[i + 1]) > 1) {
				b = true;
				cout << "YES\n";
				cout << i << " " << i + 1 << '\n';
				break;
			}
		}
		if(b == false)
		    cout << "NO\n";
	}
}