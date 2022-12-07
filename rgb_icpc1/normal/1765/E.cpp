#include "bits/stdc++.h"
//#include "iostream"
//#include "vector"
//#include "queue"
//#include "cmath"
//#include "algorithm"
using namespace std;

#define endl '\n'
#define pb push_back
#define pob pop_back
template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
typedef long long LL;
typedef pair<int, int> PI;
typedef vector<int> VI;

#define MX 1000005
#define inf 1e9
int n, a, b; 

void solve() {
	cin >> n >> a >> b;
	if (a > b) cout << 1 << endl;
	else cout << (n + a - 1) / a << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int tc; cin >> tc;
	while (tc --) {
		solve();
	}
	

	return 0;
}