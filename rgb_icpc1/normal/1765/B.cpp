#include "iostream"
#include "vector"
#include "queue"
#include "cmath"
#include "algorithm"
#include "iostream"
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
string s;

void solve() {
	int n; cin >> n >> s;
	for (int i = 1; i < n; i += 3) {
		if (i + 1 == n || s[i] != s[i + 1]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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