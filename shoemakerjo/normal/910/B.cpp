#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	int o1 = 2;
	int take = (n-b)/a;
	take = take*2;
	if (take < 4) {
		if (take == 0) {
			if (a*4 <= n) o1 += 1;
			else if (a*2 <= n) o1 += 2;
			else o1 += 4;
		} 
		if (take == 2) {
			if (a*2 <= n) o1++;
			else o1 += 2;
		}
	}
	int o2 = 20;
	if (b*2 <= n) {
		o2 = 1;
		int take = (n-b*2)/a;
		if (take == 0) {
			if (a*4 <= n) {
				o2++;
			}
			else if (a*3 <= n) {
				o2 += 2;
			}
			else if (a*2 <= n) {
				o2 += 2;
			}
			else o2 += 4;
		}
		if (take == 1) {
			if (a*3 <= n) {
				o2++;
			}
			else {
				if (a*2 <= n) {
					o2+=2;
				}
				else {
					o2 += 3;
				}
			}
		}
		if (take == 2) {
			o2++;
		}
		if (take == 3) {
			o2++;
		}
		//4 leads to no increase
	}
	// cout << o1 << "  -  " << o2 << endl;
	cout << min(o1, o2) << endl;
	cin >> n;
}