#include <bits/stdc++.h>
#define ll long long
#define maxn 55 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi pair<int, int>
using namespace std;
vector<pi> otp;
int fl[maxn][maxn];
void act(int u, int v) {
	otp.pb(mp(u, v));
	if (fl[u][v] == 1) fl[u][v] = 0, fl[u + 1][v] = 0, fl[u][v + 1] = fl[u + 1][v + 1] = -1;
	else {
		fl[u][v] = 1, fl[u][v + 1] = 1, fl[u + 1][v] = fl[u + 1][v + 1] = -1;
	}
}
int c[maxn][maxn];
char inp[maxn];
void work(int a, int b, int to) {
	if (fl[a][b] == -1) {
		if (fl[a][b - 1] == 0) work(a, b - 1, 1);
		else work(a - 1, b, 0);
		work(a, b, to);
		return ;
	}
//	cout << "!!!" << "WORK" << a << ' ' << b << ' ' << to << ' ' << fl[a][b] << endl;
	if (fl[a][b] == to) return;
	if (fl[a][b] == 1) work(a, b + 1, 1);
	else work(a + 1, b, 0);
	act(a, b);
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	memset(fl, -1, sizeof(fl));
//	cout << n << ' ' << m << endl;
	for (int cs = 0; cs < 2; cs++) {
		for (int i = 1; i <= n; i++) {
			scanf("%s", inp + 1);
			for (int j = 1; j <= m; j++) {
				int tp = 0;
				if (inp[j] == 'U') tp = 1;
				else if (inp[j] == 'L') tp = 0;
				else tp = -1;
				if (cs == 0) fl[i][j] = tp;
				else c[i][j] = tp; 
			}
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (c[i][j] == -1) continue;
			else if (fl[i][j] != c[i][j])
				work(i, j, c[i][j]);
	cout << otp.size() << endl;
	for (auto v : otp)
		printf("%d %d\n", v.fi, v.se);
	return 0;
}
/*
3
? ? 
? ?  
? ? 
*/