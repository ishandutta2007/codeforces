#include<bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
using LL = long long;
using PI = pair<int, int>;
#define endl '\n'
const int N = 1000005;
int a[N], b[N];
string s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T --) {
		int n; cin >> n;
		for (int i = 1; i < n; i ++) cout << i + 1 << ' ';
		cout << 1 << endl;
	}
	return 0;
}