#include <bits/stdc++.h>
using namespace std;
#define maxn 20010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
char inp[maxn];
int fl[maxn][26], cnt[maxn];
int main() {
	scanf("%s", inp);
	int l = strlen(inp);
	for (int i = l; i < 2 * l; i++)
		inp[i] = inp[i - l];
	db ans = 0;
	for (int i = 0; i < 26; i++) {
		memset(fl, 0, sizeof(fl));
		int ct = 0;
		for (int j = 0; j < l; j++) {
			ct++;
			if (inp[j] == 'a' + i) {
				for (int k = j; k < j + l; k++)
					fl[k - j][inp[k] - 'a']++;
			}
		}
		int mxs = 0;
		for (int i = 0; i < l; i++) {
			cnt[i] = 0;
			for (int j = 0; j < 26; j++)
				cnt[i] += (fl[i][j] == 1);
			mxs = max(mxs, cnt[i]);
	//		if (mxs == 2) cout << "!!!" << i << endl;
		}
	//	cout << i << ' ' << mxs << endl;
		ans += 1.0 * mxs / l;
	}
	printf("%.10lf\n", ans);
	return 0;
}