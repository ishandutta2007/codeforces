#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 1E5 + 10, MAXL = 1E5 + 10, MAXSL = 1E6 + 10;

int n, K, q;
int a[MAXSL];
char s[MAXSL], buf[MAXL];

struct TrieGraph{
	static const int MAXNN = 2E6 + 10, SIGMA = 26;
	int cnt, child[MAXNN][SIGMA];
	int mark[MAXNN], fail[MAXNN];

	int getNode(){
		memset(child + cnt, -1, sizeof child[0]);
		mark[cnt] = -1;
		return cnt++;
	}

	void init(){
		cnt = 0;
		getNode();
	}

	void insert(char *buf, int c){
		int u = 0, i;
		for (; *buf; ++buf){
			i = *buf - 'a';
			if (!~child[u][i])
				child[u][i] = getNode();
			u = child[u][i];
		}
		mark[u] = c;
	}

	void build(){
		queue<int> Q;
		int u = 0;
		for (int i = 0; i < SIGMA; ++i)
			if (~child[u][i])
				fail[child[u][i]] = u, Q.push(child[u][i]);
			else
				child[u][i] = u;
		while (!Q.empty()){
			u = Q.front(), Q.pop();
			for (int i = 0; i < SIGMA; ++i)
				if (~child[u][i])
					fail[child[u][i]] = child[fail[u]][i], Q.push(child[u][i]);
				else
					child[u][i] = child[fail[u]][i];
		}
	}
}Trie;

int main(){
	scanf("%d%d", &n, &K);
	scanf("%s", s);
	scanf("%d", &q);
	Trie.init();
	for (int i = 1; i <= q; ++i){
		scanf("%s", buf);
		Trie.insert(buf, i);
	}
	Trie.build();

	int u = 0;
	for (int i = 0; i < K - 1; ++i)
		u = Trie.child[u][s[i] - 'a'];
	for (int i = K - 1; s[i]; ++i)
		a[i] = Trie.mark[u = Trie.child[u][s[i] - 'a']];
	for (int i = 0; i < K - 1; ++i)
		a[i] = Trie.mark[u = Trie.child[u][s[i] - 'a']];

	for (int i = 0; i < K; ++i){
		vector<int> t;
		for (int j = 0; j < n; ++j)
			t.push_back(a[j * K + i]);
		sort(t.begin(), t.end());
		int m = unique(t.begin(), t.end()) - t.begin();
		if (t[0] == -1 || m != n){
			if (i == K - 1)
				puts("NO");
			continue;
		}
		puts("YES");
		for (int j = 0; j < n; ++j)
			printf("%d%c", a[j * K + i], "\n "[j + 1 < n]);
		break;
	}
	
	return 0;
}