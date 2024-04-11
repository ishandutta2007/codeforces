#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
const int N = 405;
int n;
int f[N][N][3][3], g[N][N][3][3];
void add(int &x,int y) {
	x += y; if (x>=MOD) x-=MOD;
}
int p[N][2][2], q[N][2][2];
void init() {

	f[0][0][0][0] = 1;
	for (int i = 1; i <= n; i ++) {
		for (int x = 0; x < N; x ++) {
			for (int y = 0; y < N; y ++) {
				for (int f1 = 0; f1 < 3; f1 ++) for (int f2 = 0; f2 < 3; f2 ++) {
					if (f[x][y][f1][f2]) {
						if (f1 != 1) add(g[x+1][y][f2][1], f[x][y][f1][f2]);
						if (f1 != 2) add(g[x][y+1][f2][2], f[x][y][f1][f2]);
			
						add(g[x][y][f2][0], 1LL * f[x][y][f1][f2] * ((f1>0||i<=2)?24LL:23LL) % MOD);
					}
				}
			}
		}
		for (int x = 0; x < N; x ++) 
			for (int y = 0; y < N; y ++) 
				for (int f1 = 0; f1 < 3; f1 ++) for (int f2 = 0; f2 < 3; f2 ++) {
					f[x][y][f1][f2] = g[x][y][f1][f2]; g[x][y][f1][f2] = 0;
				}

	}

	p[0][0][0] = 1;
	for (int i = 1; i <= n; i ++) {
		for (int x = 0; x < i; x ++) {
			for (int f1 = 0; f1 < 2; f1 ++) {
				for (int f2 = 0; f2 < 2; f2 ++) {
					if (p[x][f1][f2]) {
						if (f1 != 1) add(q[x+1][f2][1], p[x][f1][f2]);
						add(q[x][f2][0], 1LL * p[x][f1][f2] * ((f1>0||i<=2)?25LL:24LL)  % MOD);
					}
				}
			}
		}
		for (int x = 0; x <= i; x ++) 
				for (int f1 = 0; f1 < 2; f1 ++) for (int f2 = 0; f2 < 2; f2 ++) {
					p[x][f1][f2] = q[x][f1][f2]; q[x][f1][f2] = 0;
				}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	init();


	vector<int> c(26);
	for (int i = 0; i < 26; i ++) {
		cin >> c[i];
		//c[i] = n / 3 + rand() % 3; c[i] = min(c[i], n);
	}
	//for (int i = 0; i < 26; i ++) cout << c[i] << " "; cout << endl;
	LL ans = 26 * 26;
	for (int i = 1; i <= n - 2; i ++) ans = ans * 25 % MOD;

	LL s[N] = {0}, ss[N][N] = {0};
	for (int i = N - 2; i >= 0; i --) {
		for (int x = 0; x < 2; x ++) for (int y = 0; y < 2; y ++) (s[i] += p[i][x][y]) %= MOD;
		s[i] += s[i+1]; s[i] %= MOD;
	}
	for (int i = N - 2; i >= 0; i --) for (int j = N - 2; j >= 0; j --) {
		for (int x = 0; x < 3; x ++) for (int y = 0; y < 3; y ++) {
			(ss[i][j] += f[i][j][x][y]) %= MOD;	
		}
		/*
		if (ss[i][j]) {
			printf("ss[%d][%d] = %lld\n", i,j,ss[i][j]);
		}
		*/
	}
	for (int i = N - 2; i >= 0; i --) for (int j = N - 2; j >= 0; j --) {
		ss[i][j] = (ss[i+1][j] + ss[i][j+1] + ss[i][j] - ss[i+1][j+1]) % MOD;
		ss[i][j] = (ss[i][j] % MOD + MOD) % MOD;
	}
	//cout << ans << endl;
	//cout << s[2] << endl;
	for (int i = 0; i < 26; i ++) {
		ans = ans - s[c[i] + 1]; ans = (ans % MOD + MOD) % MOD;
	}
	//cout << ans << endl;
	for (int i = 0; i < 26; i ++) {
		for (int j = i + 1; j < 26; j ++) {
			assert(ss[c[i]+1][c[j]+1] == ss[c[j]+1][c[i]+1]);
			ans = ans + ss[c[i] + 1][c[j] + 1]; ans = (ans % MOD + MOD) % MOD;
		}
	}
	cout << ans << endl;
}