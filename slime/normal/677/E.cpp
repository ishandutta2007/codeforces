#include <bits/stdc++.h>
#define ll long long
#define maxn 1005 /*rem*/
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
int mv[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, -1}, {-1, -1}, {-1, 1}, {1, 1}};
int cnt[maxn][maxn][8][4];
int tts[maxn][maxn][8];
int n;
int fl[maxn][maxn];
bool chk(int a, int b) {
	if (a >= 1 && a <= n && b >= 1 && b <= n) return 1;
	return 0;
}
void gt(int a, int b, int c) {
	if (tts[a][b][c] != -1) return ;
	int x = a + mv[c][0], y = b + mv[c][1];
	if (chk(x, y)) {
		gt(x, y, c);
		tts[a][b][c] = tts[x][y][c] + 1;
		for (int j = 0; j < 4; j++)
			cnt[a][b][c][j] = cnt[x][y][c][j];
		cnt[a][b][c][fl[a][b]]++;
	}
	else {
		tts[a][b][c] = 1;
		cnt[a][b][c][fl[a][b]] = 1;
	}	
	if (!fl[a][b]) tts[a][b][c] = 0;
}
char inp[maxn];
int main() {
	memset(tts, -1, sizeof(tts));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%s", inp + 1);
		for (int j = 1; j <= n; j++) 
			fl[i][j] = inp[j] - '0';
	}
	for (int i = 0; i < 8; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				gt(j, k, i);
	int c[4] = {1, 0, 0, 0};
	db ca = -1000;
	db r = log(2), g = log(3);
	for (int i = 0; i < 8; i += 4)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++) {
				if (fl[j][k] == 0) continue;
				int d[4] = {0, 0, 0, 0};
				int q = 1e9;
				for (int s = i; s < i + 4; s++)
					q = min(q, tts[j][k][s]);
				for (int s = i; s < i + 4; s++) {
					int x = j + mv[s][0] * (q - 1), y = k + mv[s][1] * (q - 1);
				//	cout << i << ' ' << j << ' ' << s << ' ' << x << ' ' << y << ' ' << cnt[x][y][s ^ 2][0] << endl; 
					for (int g = 0; g < 4; g++)
						d[g] += cnt[x][y][s ^ 2][g] - cnt[j][k][s ^ 2][g];
				}
			//	cout << i << ' ' << j << ' ' << k << ' ' << d[2] << ' ' << d[3] << endl;
				d[fl[j][k]]++;
				db cur = d[2] * r + d[3] * g;
				if (cur > ca) {
					ca = cur;
					for (int j = 0; j < 4; j++)
						c[j] = d[j];
				}
			}
	ll res = 1;
	for (int i = 0; i < 4; i++) res *= ksm(i, c[i]), res %= mod;
	cout << res << endl;
	return 0;
}