#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
vi cur[18][maxn]; 
char inp[maxn];
int dv[maxn];
int n;
int main() {
	cin >> n;
	scanf("%s", inp);
	for (int i = 0; i < n; i++) {
		int c = (inp[i] - '0');
		if (i) c ^= (inp[i - 1] - '0');
		for (int j = 0; j < 18; j++)
			cur[j][i % (1 << j)].pb(c);
	}
	for (int j = 0; j < 18; j++)
		for (int k = 0; k < maxn && k < (1 << j); k++)
			for (int s = 1; s < cur[j][k].size(); s++)
				cur[j][k][s] += cur[j][k][s - 1];
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		int ans = 0;
		int cnt[18][2];
		for (int j = 0; j < 18; j++) {
			int dv = l % (1 << j);
			int ls = l / (1 << j), rs = ls + (r - l) / (1 << j);
			int cans = cur[j][dv][rs] - cur[j][dv][ls];
			cnt[j][0] = cans, cnt[j][1] = rs - ls - cans;
		//	cans = min(cans, rs - ls - cans);
		//	cout << j << ' ' << dv << ' ' << ls << ' ' << rs << ' ' << cur[j][dv][ls] << ' ' << cur[j][dv][rs] << endl;
		//	ans += cans; 
		}
		
		for (int j = 0; j < 17; j++)
			cnt[j][0] -= cnt[j + 1][0], cnt[j][1] -= cnt[j + 1][1];
		for (int j = 0; j < 18; j++)
			ans += min(cnt[j][0], cnt[j][1]);
		ans = (ans + 1) / 2;
		printf("%d\n", ans);
	}
	return 0;
}