#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

int main() {
	int t;
	cin >> t;
	rep(i, 0, t) {
		int n;
		cin >> n;
		vector<int> check(n);
		vector<int> princesses;
		fill(all(check), 0);
		rep(j, 0, n) {
			int k;
			cin >> k;
			int falsse = 0;
			rep(l, 0, k) {
				int tmp;
				cin >> tmp;
				tmp--;
				if (falsse == 0) {
					if (check[tmp] == 0) {
						check[tmp] = 1;
						falsse = 1;
					}
				}
			}
			if (falsse == 0) {
				princesses.push_back(j);
			}
		}
		if (princesses.empty()) {
			cout << "OPTIMAL\n";
		}
		else {
			cout << "IMPROVE\n";
			cout << princesses[0]+1 << " ";
			int smsmsm = 1;
			rep(j, 0, check.size()) {
				if (check[j] == 0 && smsmsm == 1) {
					cout << j + 1 << endl;
					smsmsm = 0;
				}
			}
		}
	}
	return 0;
}