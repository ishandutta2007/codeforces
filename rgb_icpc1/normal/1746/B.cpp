#include <bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
#define PYES puts("YES");
#define PNO puts("NO");
#define pb push_back
#define pob pop_back
#define endl '\n'
using LL = long long;
using PI = pair<int, int>;
using VI = vector<int>;
using VP = vector<PI>;

#define N 1000005
int a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int Tc, n; cin >> Tc;
	while(Tc--) {
		cin >> n;
		for (int i = 0; i < n; i ++) cin >> a[i];
		int s = 0, j = 0;
		for (int i = n - 1; i >= 0 && j < i; i --) {
			if (a[i] == 1) continue;
			else {
				while (j < i && a[j] == 0) j ++;
				if (j >= i) break;
				j ++; s ++;
			}
		}
		cout << s << endl;
	}

	return 0;
}