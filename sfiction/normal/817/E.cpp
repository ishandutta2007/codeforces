#include <bits/stdc++.h>

#define st first
#define nd second
#define all(x) (x).begin(), (x).end()

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

template <class T> void mini(T &l, T r){l = min(l, r);}
template <class T> void maxi(T &l, T r){l = max(l, r);}

template <class TH> void _dbg(const char *sdbg, TH h){cerr << sdbg << "=" << h << "\n";}
template <class TH, class ...TA> void _dbg(const char *sdbg, TH h, TA... a){
	while (*sdbg != ',') cerr << *sdbg++; cerr << "=" << h << ","; _dbg(sdbg + 1, a...);
}
template <class T> ostream &operator <<(ostream &os, vector<T> V){
	os << "["; for (auto vv: V) os << vv << ","; return os << "]";
}
template <class L, class R> ostream &operator <<(ostream &os, pair<L, R> P){
	return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef SFIC
	#define eput(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
	#define eput(...) 218
#endif

const int MAXN = 1E5 + 10;

struct TrieGraph{
	static const int SIGMA = 2, D = 28, MAXN = ::MAXN * D;
	int cnt, child[MAXN][SIGMA], fail[MAXN];
	int size[MAXN];

	int getNode(){
		memset(child[cnt], -1, sizeof(child[0]));
		size[cnt] = 0;
		return cnt++;
	}

	void init(){
		cnt = 0;
		getNode();
	}

	void insert(int s){
		int u = 0, i;
		++size[0];
		for (int j = D - 1; j >= 0; --j){
			i = s >> j & 1;
			if (!~child[u][i])
				child[u][i] = getNode();
			u = child[u][i];
			++size[u];
		}
	}

	void erase(int s){
		int u = 0, i;
		--size[0];
		for (int j = D - 1; j >= 0; --j){
			i = s >> j & 1;
			if (!~child[u][i])
				child[u][i] = getNode();
			u = child[u][i];
			--size[u];
		}
	}

	int query(int s, int l){
		int u = 0, i, ret = 0;
		for (int j = D - 1; j >= 0; --j){
			eput(s, j, u, size[u]);
			i = s >> j & 1;
			if ((l >> j & 1)){
				ret += ~child[u][i] ? size[child[u][i]] : 0;
				i ^= 1;
			}
			if (!~child[u][i])
				break;
			u = child[u][i];
		}
		return ret;
	}
}Trie;

int main(){
	int n;
	scanf("%d", &n);
	Trie.init();
	for (int qi = 0; qi < n; ++qi){
		int type, p, l;
		scanf("%d%d", &type, &p);
		if (type == 1)
			Trie.insert(p);
		else if (type == 2)
			Trie.erase(p);
		else{
			scanf("%d", &l);
			printf("%d\n", Trie.query(p, l));
		}
	}
	return 0;
}