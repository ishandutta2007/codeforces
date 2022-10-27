#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t; cin >> t;
	while (t --) {
		int n, m;
		cin >> n >> m;
		vector<string> s(n);
		for (int i = 0; i < n; i ++) cin >> s[i];
		
		bool fd = 0;
		for (int f = 0; f < 2; f ++) {
			bool ok = 1;
			for (int i = 0; i < n; i ++) {
				for (int j = 0; j < m; j ++) {
					if ((i+j)%2 == f && s[i][j] == 'R') ok = false;
					if ((i+j)%2 == (f^1) && s[i][j] == 'W') ok = false;
				}
			}
			if (ok) {
				fd = 1;
				cout << "YES" << endl;
				for (int i = 0; i < n; i ++) {
					for (int j = 0; j < m; j ++) {
						cout << ((i+j)%2==f?'W':'R');
					}
					cout<<endl;
				}
				break;
			}
		}
		if (! fd) {
			cout << "NO" << endl;
		}
	}
}