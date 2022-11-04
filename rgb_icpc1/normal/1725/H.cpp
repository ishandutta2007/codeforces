#include <bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
#define pb push_back
#define pob pop_back
#define endl '\n'
using LL = long long;
using PI = pair<int, int>;
const int N = 1000005;

int n;
int a[N];
int b[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	int c0 = 0, c1 = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 3 == 0) c0++;
		else c1++;
	}
	if (c0 > n / 2) {
		for (int i = 0, j = 0; i < n; i++) {
			if (a[i] % 3 != 0) b[i] = 0;
			else {
				if (j < c0 - n / 2) {
					j++;
					b[i] = 0;
				}
				else b[i] = 1;
			}
		}
		cout << 2 << endl;
		for (int i = 0; i < n; i++) cout << b[i]; cout << endl;
	}
	else {
		for (int i = 0, j = 0; i < n; i++) {
			if (a[i] % 3 == 0) b[i] = 0;
			else {
				if (j < c1 - n / 2) {
					j++;
					b[i] = 0;
				}
				else b[i] = 1;
			}
		}
		cout << 0 << endl;
		for (int i = 0; i < n; i++) cout << b[i]; cout << endl;
	}
	
	return 0;
}