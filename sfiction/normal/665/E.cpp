#include <cstdio>
#include <cstring>

typedef long long ll;

const int MAXN = 1E6 + 10, MAXL = 30;

int n, K;
int a[MAXN];

struct Trie{
	static const int MAXNN = MAXN * MAXL, SIGMA = 2;
	int tot, child[MAXNN][2];
	int size[MAXNN];

	int getNode(){
		memset(child[tot], -1, sizeof(child[0]));
		size[tot] = 0;
		return tot++;
	}

	void init(){
		tot = 0;
		getNode();
	}

	void insert(int val){
		int u = 0, v;
		for (int i = MAXL - 1; i >= 0; --i){
			++size[u];
			v = val >> i & 1;
			if (!~child[u][v])
				child[u][v] = getNode();
			u = child[u][v];
		}
		++size[u];
	}

	int query(int val){
		int u = 0, v, vk = val ^ K;
		int ret = 0;
		for (int i = MAXL - 1; i >= 0; --i){
			v = vk >> i & 1;
			if ((K >> i & 1) == 0 && ~child[u][!v])
				ret += size[child[u][!v]];
			if (!~child[u][v])
				return ret;
			u = child[u][v];
		}
		return ret += size[u];
	}
}trie;

int main(){
	scanf("%d%d", &n, &K);
	ll ans = 0;
	trie.init();
	trie.insert(0);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		trie.insert(a[i] ^= a[i - 1]);
		ans += trie.query(a[i]);
	}
	printf("%I64d\n", ans);
	return 0;
}