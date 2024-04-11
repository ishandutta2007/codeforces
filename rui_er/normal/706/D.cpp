//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const int N = 2e5+5, K = N * 32;

struct Trie {
	int s[K][2], tag[K], tot;
	Trie() : tot(1) {fil(s, 0); fil(tag, 0); /*puts("INIT TRIE");*/}
	~Trie() {/*puts("DELETE TRIE");*/}
	void insert(int val) {
		int u = 1;
		per(i, 30, 0) {
			int c = (val >> i) & 1;
			if(!s[u][c]) s[u][c] = ++tot;
			u = s[u][c];
			++tag[u];
		}
	}
	void delet_(int val) {
		int u = 1;
		per(i, 30, 0) {
			int c = (val >> i) & 1;
			u = s[u][c];
			--tag[u];
		}
	}
	int query(int val) {
		int u = 1, ans = 0;
		per(i, 30, 0) {
			int c = (val >> i) & 1;
			if(s[u][c^1] && tag[s[u][c^1]]) ans |= (1 << i), u = s[u][c^1];
			else u = s[u][c];
		}
		return ans;
	}
}trie;

int main() {
	trie.insert(0);
	mulT0 {
		char op[2]; int x;
		scanf("%s%d", op, &x);
		if(op[0] == '+') trie.insert(x);
		else if(op[0] == '-') trie.delet_(x);
		else printf("%d\n", trie.query(x));
	}
	return 0;
}