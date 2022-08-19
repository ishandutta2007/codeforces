#include <bits/stdc++.h>
#define ll long long
#define maxn 200005
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;

vi eg[maxn], bk[maxn];
int fl[maxn][2];
void st(int a, int tp, int x) {
	if (fl[a][tp]) return ;
	fl[a][tp] = x;
	for (auto v : eg[a])
		st(v, tp ^ 1, a);
}
int d[maxn];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int c;
		scanf("%d", &c);
		eg[i].resize(c);
		for (int j = 0; j < c; j++)
			scanf("%d", &eg[i][j]), 
			bk[eg[i][j]].pb(i);
	}
	int pl;
	scanf("%d", &pl);
	st(pl, 0, -1);
	for (int i = 1; i <= n; i++) {
		if (eg[i].size() == 0 && fl[i][1]) {
			printf("Win\n");
			vi cur;
			int ct = 1;
			while (i != pl || ct != 0) {
				cur.pb(i), i = fl[i][ct], ct ^= 1;
			}
			cur.pb(pl);
			for (int i = cur.size() - 1; i >= 0; i--)
				printf("%d ", cur[i]);
			printf("\n");
			return 0;
		}
	}
	for (int i = 1; i <= n; i++)	
		d[i] = eg[i].size();
	queue<int> cur;
	for (int i = 1; i <= n; i++)
		if (!d[i]) cur.push(i);
	while (!cur.empty()) {
		int v = cur.front();
		cur.pop();
		for (auto s : bk[v]) {
			d[s]--;
			if (d[s] == 0) 
				cur.push(s);
		}
	}
	if (d[pl] == 0) printf("Lose\n");
	else printf("Draw\n");
	return 0;
}