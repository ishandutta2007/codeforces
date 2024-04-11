//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 2005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
vi u[3];
char s[12][10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int nd[maxn][10];
int fl[maxn][maxn];
int re[maxn][maxn];
char ur[10];
int main() {
	int n, k;
	cin >> n >> k;
	for (int j = 0; j < n; j++) {
		scanf("%s", ur);
		for (int t = 0; t < 10; t++) {
			int cnt = 0;
			int fl = 1;
			for (int m = 0; m < 7; m++) {
				int fn = s[t][m] - '0', cu = ur[m] - '0';
				if (fn == 0 && cu == 1) fl = 0;
				cnt += fn - cu;
			}
			if (!fl) cnt = maxn;
			nd[j][t] = cnt;
		}
	}
	for (int j = n; j >= 0; j--)
		for (int s = 0; s <= k; s++) {
			if (j == n) {
				if (s == 0) fl[j][s] = 1;
				else fl[j][s] = 0;
			}
			else {
				for (int t = 0; t < 10; t++) {
					if (nd[j][t] > s) continue;
					if (fl[j + 1][s - nd[j][t]]) {
						fl[j][s] = 1;
						re[j][s] = t;
					}
				}
			}
		}
	if (!fl[0][k]) cout << -1 << endl;
	else {
		int uk = k, uj = 0;
		while (uj < n) {
			printf("%d", re[uj][uk]);
			uk -= nd[uj][re[uj][uk]];
			uj++; 
		} 
		printf("\n");
	}
	return 0;
}