#include <bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
#define pb push_back
#define pob pop_back
#define endl '\n'
using LL = long long;
using PI = pair<int, int>;
using VI = vector<int>;
const int MX = 1000005;
int a[MX];
int res[MX];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int Tc; cin >> Tc;
	while (Tc --) {
		int n; cin >> n;
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
			res[n - a[i]] = i + 1;
		}
		for (int i = 0; i < n; i ++) cout << res[i] << " ";
		cout << endl;
	}
	
	return 0;
}