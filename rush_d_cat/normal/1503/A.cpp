#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n; string s;
		cin >> n >> s;
		vector<int> f1(n, 0), f2(n, 0);

		int one = 0;
		for (int i = 0; i < n; i ++) if (s[i] == '1') one ++;

		if (one & 1) {
			cout << "NO" << endl; continue;
		}

		int cur_one = 0, flag = 0; 
		for (int i = 0; i < n; i ++) {
			if (s[i] == '1') {
				cur_one ++;
				if (cur_one <= one / 2) {
					f1[i] = f2[i] = 1;
				} else {
					f1[i] = f2[i] = -1;
				} 
			} else {
				if (flag == 0) {
					f1[i] = 1; f2[i] = -1; 
				} else {
					f1[i] = -1; f2[i] = 1;
				}
				flag ^= 1;
			}
		}

		bool ok = true;

		{
			int sum = 0;
			for (int i = 0; i < n; i ++) {
				sum += f1[i];
				if (sum < 0) ok = false;
			}
			if (sum != 0) ok = false;
		}
		{
			int sum = 0;
			for (int i = 0; i < n; i ++) {
				sum += f2[i];
				if (sum < 0) ok = false;
			}
			if (sum != 0) ok = false;
		}

		if (ok) {
			cout << "YES" << endl;
			for (int i = 0; i < n; i ++) {
				cout << (f1[i]==1?'(':')');
			}
			cout << endl;
			for (int i = 0; i < n; i ++) {
				cout << (f2[i]==1?'(':')');
			} 
			cout << endl;
		} else {
			cout << "NO" << endl; 
		}
    }
}