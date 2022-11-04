#include <bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
#define pb push_back
#define pob pop_back
#define endl '\n'
using LL = long long;
using PI = pair<int, int>;
const int N = 100005;

int n, m;
int a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int Tc; cin >> Tc;
	while (Tc --) {
		cin >> n >> m;
		if(n == 1) {
			cout << "YES" << endl;
			cout << m << endl;
			continue;
		}
		if(m < n) {
			cout << "NO" << endl;
			continue;
		}
		int flg = 0;
		if(n % 2 == 0) {
			if(m % 2 != 0) cout << "NO" << endl;
			else {
				cout << "YES" << endl;
				for(int i = 0; i < n - 2; i++) cout << 1 << ' ';
				cout << (m - n + 2) / 2 << ' ' << (m - n + 2) / 2 << endl;
			}
		}
		else {
			cout << "YES" << endl;
			for(int i = 0; i < n - 1; i++) cout << 1 << ' ';
			cout << m - n + 1 << endl;
		}
	}
	return 0;
}