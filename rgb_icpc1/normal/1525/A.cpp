#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i ++)
using namespace std;
const int mx = 100005;
#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;

int main() {

#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int Tc;
	for (cin >> Tc; Tc--; ) {
		int k;
		cin >> k;
		int g = __gcd(k, 100 - k);
		cout << 100 / g << endl;
	}
	

}