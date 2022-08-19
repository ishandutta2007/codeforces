#include <bits/stdc++.h>
#define ll long long
#define maxn 105 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
char inp[maxn][maxn];

char fn(int a) {
	if (a <= 26) return a - 1 + 'a';
	else if (a <= 52) return (a - 27) + 'A';
	else return (a - 53) + '0';
}
int ss[maxn][maxn];
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		vector<pi> res;
		int r, c, k;
		scanf("%d%d%d", &r, &c, &k);
		int tot = 0;
		for (int i = 1; i <= r; i++) {
			scanf("%s", inp[i] + 1);
			for (int j = 1; j <= c; j++)
				if (inp[i][j] == 'R') tot++;
		}
		for (int i = 1; i <= r; i++)
			if (i % 2 == 1)
				for (int j = 1; j <= c; j++)
					res.pb(mp(i, j));
			else
				for (int j = c; j >= 1; j--)
					res.pb(mp(i, j));
		vi s;
		for (int i = 1; i <= k; i++)
			s.pb(tot / (k + 1 - i)), 
		//	cout << "!!!" << tot / (k + 1 - i) << endl,
			tot -= (tot / (k + 1 - i));
		int pl = 0;
		for (int i = 0; i < k; i++) {
			int ncnt = 0;
			while (pl < res.size() && ncnt + (inp[res[pl].fi][res[pl].se] == 'R') <= s[i]) {
				ncnt += (inp[res[pl].fi][res[pl].se] == 'R');
				ss[res[pl].fi][res[pl].se] = i + 1;
				pl++;
			}
		}
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				printf("%c", fn(ss[i][j]));
			}
			printf("\n");
		}
	} 
	return 0;
}