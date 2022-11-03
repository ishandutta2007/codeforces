#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 1E2 + 10, MAXL = 2E2 + 5;

struct mat{
	static int n;
	ll a[MAXL][MAXL];

	void clear(){
		for (int i = 0; i < n; ++i)
			fill_n(a[i], n, 0);
	}
};

int mat::n;

mat operator *(mat &l, mat &r){
	mat ret;
	for (int i = 0; i < mat::n; ++i)
		for (int j = 0; j < mat::n; ++j)
			ret.a[i][j] = LLONG_MIN;
	for (int i = 0; i < mat::n; ++i)
		for (int k = 0; k < mat::n; ++k)
			for (int j = 0; j < mat::n; ++j)
				ret.a[i][j] = max(ret.a[i][j], l.a[i][k] + r.a[k][j]);
	return ret;
}

struct TrieGraph{
	static const int SIGMA = 26, MAXNode = MAXL;
	int cnt, child[MAXNode][SIGMA], fail[MAXNode];
	int cntPat, end[MAXNode];

	inline int getNode(){
		memset(child[cnt], -1, sizeof(child[0]));
		end[cnt] = 0;
		return cnt++;
	}

	void init(){
		cnt = 0;
		getNode();
	}

	void insert(char *s, int c){
		int u = 0, i;
		for (; *s; ++s){
			if (!~child[u][i = *s - 'a'])
				child[u][i] = getNode();
			u = child[u][i];
		}
		end[u] += c;
	}

	void build(){
		queue<int> Q;
		fail[0] = 0;
		for (int i=0;i<SIGMA;++i)
			if (~child[0][i]){
				fail[child[0][i]] = 0;
				Q.push(child[0][i]);
			}
			else
				child[0][i] = 0;

		int u;
		while (!Q.empty()){
			u = Q.front();
			Q.pop();
			end[u] += end[fail[u]];
			for (int i=0;i<SIGMA;++i)
				if (~child[u][i]){
					fail[child[u][i]] = child[fail[u]][i];
					Q.push(child[u][i]);
				}
				else
					child[u][i] = child[fail[u]][i];
		}
	}

	void getMat(mat &a){
		static const ll INF = -1ll << 62;
		mat::n = cnt;
		for (int i = 0; i < cnt; ++i){
			for (int j = 0; j < cnt; ++j)
				a.a[j][i] = LLONG_MIN >> 1;
			for (int j = 0; j < SIGMA; ++j)
				a.a[child[i][j]][i] = end[child[i][j]];
		}
	}
}AC;

mat e, res;

int a[MAXN];
char buf[MAXL];

int main(){
	int n;
	ll L;
	scanf("%d%I64d", &n, &L);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	AC.init();
	for (int i = 0; i < n; ++i){
		scanf("%s", buf);
		AC.insert(buf, a[i]);
	}
	AC.build();
	AC.getMat(e);
	res.clear();
	for (; L; L >>= 1, e = e * e)
		if (L & 1)
			res = res * e;
	ll ans = 0;
	for (int i = 0; i < mat::n; ++i)
		ans = max(ans, res.a[i][0]);
	printf("%I64d\n", ans);
	return 0;
}