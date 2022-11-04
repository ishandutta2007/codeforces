#include <bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
#define endl '\n'
using LL = long long;
using PII = pair<int, int>;
using VI = vector<int>;
using VPII = vector <PII>;
const int MN = 1000005;
int a[MN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int Tc; cin >> Tc;
	while (Tc --) {
		int n; cin >> n;
		cout << n << endl;
	}
	return 0;
}