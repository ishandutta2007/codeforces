#include <bits/stdc++.h>

using namespace std;



#define N 101010



int n, w[N], qq, par[N][20], dp[N], p[N/10], pc;



const int mod = 1e9 + 7;



vector <int> E[N];



struct query {

	int a, b, x;

}Q[N];



int Up(int a, int d) {

	int i = 0;

	while (d) {

		if (d & 1) a = par[a][i];

		i ++;

		d >>= 1;

	}

	return a;

}

int lca(int a, int b) {

	if (dp[a] < dp[b])return lca(b, a);

	a = Up(a, dp[a] - dp[b]);

	for (int i = 17; i >= 0; i--)if (par[a][i] != par[b][i])a = par[a][i], b = par[b][i];

	if (a != b)a = par[a][0];

	return a;

}



typedef pair <int, int> pii;



vector <pii> V;

map <int, int> mp;

vector <vector <int> > G[N*2];

vector <vector <pii> > U[N*2];

void Fact(int a) {

	int i;

	V.clear();

	for (i = 0; p[i]*p[i]<=a; i++) {

		if (a%p[i] == 0) {

			int c = 0;

			while (a%p[i] == 0) {

				a /= p[i];

				c++;

			}

			V.push_back({ p[i],c });

		}

	}

	if (a != 1) {

		V.push_back({ a,1 });

	}

}

int apd[N], Ed[N], cc;

void DFS(int a, int pp) {

	par[a][0] = pp;

	int i;

	apd[a] = ++ cc;

	for (i = 0; i < 18; i ++)par[a][i + 1] = par[par[a][i]][i];

	for (auto &x : E[a]) {

		if (x == pp)continue;

		dp[x] = dp[a] + 1;

		DFS(x, a);

	}

	Ed[a] = cc;

}

const int K = 1 << 17;

int IT[K<<1];



void print(int a, int c) {

	int b = apd[a] + K;

	int e = Ed[a] + K;

	while (b <= e) {

		if (b & 1) IT[b] += c;

		if (!(e & 1)) IT[e] += c;

		b = (b + 1) >> 1, e = (e - 1) >> 1;

	}

}



int Get(int a) {

	if (!a) return 0;

	int t = a + K, s  = 0;

	while (t) {

		s += IT[t];

		t >>= 1;

	}

	return s;

}



long long ans[N];

long long expmod(long long a, int b) {

	long long rlt = 1;

	while (b) {

		if (b & 1) rlt = rlt * a % mod;

		a = a * a % mod;

		b >>= 1;

	}

	return rlt;

}



void Go(int num, query q, int x) {

	int a = q.a, b = q.b;

	int l = lca(a, b);

	int c = Get(apd[a]) + Get(apd[b]) - Get(apd[l]) - Get(apd[par[l][0]]);



	ans[num] = ans[num] * expmod(x, c) % mod;

}



int main() {

	//freopen("r.in", "r", stdin);

	int a, b, j ,cnt = 0;

	for (int i = 2; i <= 10000; i ++) {

		for (j = 2; j * j <= i; j ++) if (i % j == 0) break;

		if (j * j > i) p[pc++] = i;

	}

	scanf("%d", &n);

	for (int i = 1; i < n; i ++) {

		scanf("%d%d", &a, &b);

		E[a].push_back(b);

		E[b].push_back(a);

	}

	for (int i = 1; i <= n; i ++)scanf("%d", &w[i]);

	scanf("%d", &qq);

	for (int i = 1; i <= qq; i ++)scanf("%d %d %d", &Q[i].a, &Q[i].b, &Q[i].x);

	for (int i = 1; i <= n; i ++) {

		Fact(w[i]);

		for (auto &tp : V) {

			if (!mp.count(tp.first)) mp[tp.first] = ++cnt;

			int t = mp[tp.first];

			if (G[t].size() <= tp.second + 1) {

				G[t].resize(tp.second + 1);

			}

			G[t][tp.second].push_back(i);

		}

	}

	for (int i = 1; i <= cnt; i ++)U[i].resize(G[i].size());

	for (int i = 1; i <= qq; i ++) {

		ans[i] = 1;

		Fact(Q[i].x);

		for (auto &tp : V) {

			if (!mp.count(tp.first))continue;

			int t = mp[tp.first];

			int r = 1;

			for (j = 0; j < G[t].size(); j ++) {

				U[t][j].push_back( { i,r });

				if (j < tp.second)r = r * tp.first;

			}

		}

	}

	DFS(1, 0);

	for (int i = 1; i <= cnt; i ++) {

		for (j = 0; j < G[i].size(); j ++) {

			for (auto &t : G[i][j]) {

				print(t, 1);

			}

			for (auto &t : U[i][j]) {

				Go(t.first, Q[t.first], t.second);

			}

			for (auto &t : G[i][j]) {

				print(t, -1);

			}

		}

	}

	for (int i = 1; i <= qq; i ++)printf("%I64d\n", ans[i]);



	return 0;

}