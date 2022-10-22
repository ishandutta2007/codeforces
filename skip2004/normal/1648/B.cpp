#include<vector>
#include<iostream>
#include<algorithm>

using std::cin;
using std::cout;
const int N = 3000005;
int t, n, c;
int a[N];
int w[N];
int ps[N];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> t;
	for(int i = 0;i < t;++i) {
		cin >> n >> c;
		for(int i = 0;i < n;++i) {
			cin >> a[i];
			w[a[i]] = 1;
		}
		int ok = 1;
		for(int i = 1;i <= c * 3;++i) ps[i] = ps[i - 1] + w[i];
		for(int i = 1;i <= c;++i) if(!w[i]) {
			for(int j = 1;(j - 1) * i <= c;++j) if(w[j]) {
				const int L = j * i, R = j * i + j - 1;
				if(ps[R] != ps[L - 1]) {
					ok = 0;
					break;
				}
			}
			if(!ok) break;
		}
		for(int i = 1;i <= c;++i) w[i] = 0;
		cout << (ok ? "Yes" : "No") << '\n';
	}
}