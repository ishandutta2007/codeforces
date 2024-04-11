#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
using namespace std;
vi ca[105][105]; // ijk +  * 1024  *j = 1 * 
int dp[105][6000]; // ik + 1024 *  
int cal(int x) {
	return x * (x - 1) / 2;
}
int r[105];
void work(int L, int R, int k, int bg, int tp) {
	if (L == R) {
		r[L] = bg;
		return;
	}

	int n = R - L + 1;
	int l = dp[n][k] % 1024;	
	vi ns(l), res(l);
	int rtp = dp[n][k] & 1024; 
	if (rtp) k -= cal(l);
	else k--;
	int fk = k;
	for (int j = 0; j < l; j++)
		ns[j] = ca[n][l - j][k] % 1024,
		res[j] = ca[n][l - j][k] / 1024,  
		n -= ns[j], 
		k -= res[j];
	/*
	cout << "W" << L << ' ' << R << ' ' << fk << ' ' << bg << ' ' << tp << ' ' << l << endl;
	for (int j = 0; j < l; j++)
		cout << ns[j] << ' ' << res[j] << endl;
	cout << endl;
	system("pause");
	*/
	if (rtp) {
		if (tp)
			for (int j = 0; j < l; j++)	
				work(L, L + ns[j] - 1, res[j], bg, tp ^ 1), 
				L += ns[j], bg += ns[j];
		else 
			for (int j = l - 1; j >= 0; j--)
				work(R - ns[j] + 1, R, res[j], bg, tp ^ 1), 
				R -= ns[j], bg += ns[j];
	}
	else {
		vi p(l), q(l);
		int k = l / 2;
		if (l % 2 == 0) {
			for (int j = 0; j < k; j++)
				p[j] = 2 * j + 1, 
				p[j + k] = 2 * j;
		}
		else {
			for (int j = 0; j < k; j++)
				p[j] = 2 * j + 1, 
				p[j + k] = 2 * j;
			p[2 * k] = 2 * k;
			swap(p[l - 1], p[l - 2]);
		}
		for (int i = 0; i < l; i++) {
			int nl = L;
			for (int j = 0; j < l; j++) {
				if (p[j] == i) {
					work(nl, nl + ns[j] - 1, res[j], bg, tp);
					bg += ns[j];
					break;
				}
				nl += ns[j];
			}
		}
	}
}
int main() {
	for (int i = 1; i < 101; i++) {
		for (int j = 1; j <= i; j++) {
			ca[i][j].resize(j + cal(i + 2 - j));
			if (i == 1 && j == 1) ca[1][1][1] = 1025, dp[1][1] = 1;
			else 
				if (j >= 2)
					for (int l = i; l < ca[i][j].size(); l++)
						for (int k = 1; k <= i / j; k++) {
							if (ca[i][j][l]) break;
							int mx1 = cal(k + 1), mx2 = ca[i - k][j - 1].size() - 1;
							int du = max(k, l - mx2);
							for (int s = du; s <= mx1 && s <= l; s++)
								if (dp[k][s] && ca[i - k][j - 1][l - s]) {
									ca[i][j][l] = k + s * 1024;
									break;
								}
						}
		}
		for (int l = i; l <= cal(i + 1); l++) {
			for (int m = 2; m <= i; m++) {
				int ed = l - cal(m);
				if (ca[i][m].size() > ed && ca[i][m][ed]) {
					dp[i][l] = 1024 + m;
					break;
				}
			}
			for (int m = 4; m <= i; m++) 
				if (ca[i][m].size() > l - 1 && ca[i][m][l - 1]) {
					dp[i][l] = m;
					break;
				}
			if (dp[i][l]) ca[i][1][l] = i + l * 1024;
		}
	}
	int t;
	int test = 0;
	if (test) t = 5050;
	else
		cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k;
		if (test) n = 100, k = i + 1;
		else cin >> n >> k;
		if (!dp[n][k]) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			work(1, n, k, 1, 0);
			for (int j = 1; j <= n; j++)
				printf("%d ", r[j]);
			printf("\n");
		}
	}
	return 0;
}