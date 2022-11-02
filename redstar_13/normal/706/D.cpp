#include <bits/stdc++.h>

using namespace std;

#define NN 200010
#define inf 1000000000

typedef long long INT;
typedef pair<int, int> pii;
typedef pair<pii, int> pi3;

struct Trie {
	int go[NN * 33][2], vst[NN * 33];
	int rt, ct;
	
	void Init() {
		rt = 0;
		ct = 1;
		memset(vst, 0, sizeof(vst));
		go[0][0] = go[0][1] = -1;
		return ;
	}
	
	int newnode() {
		go[ct][0] = go[ct][1] = -1;
		return ct ++;
	}
	
	void insert(int num) {
		int r = rt;
		for (int i = 30; i >= 0; i --) {
			int t = num / (1 << i);
			num %= (1 << i);
			if (go[r][t] == -1) go[r][t] = newnode();
			r = go[r][t];
			vst[r] ++;
		}
	}
	
	int del(int num) {
		int r = rt;
		for (int i = 30; i >= 0; i --) {
			int t = num / (1 << i);
			num %= (1 << i);
			r = go[r][t];
			vst[r] --;
		}
	}
	
	int calc(int num) {
		int res = 0;
		int r = rt;
		for (int i = 30; i >= 0; i --) {
			int t = num / (1 << i);
			num %= (1 << i);
			if (go[r][1 - t] == -1 || vst[go[r][1 - t]] == 0) r = go[r][t];
			else {
				r = go[r][1 - t];
				res += (1 << i);
			}
		}
		return res;
	}
} trie ;

int main() {
	
	int Q, num;
	char str[11];
	
	scanf("%d", &Q);
	trie.Init();
	trie.insert(0);
	
	for (int i = 0; i < Q; i ++) {
		scanf("%s%d", str, &num);
		if (str[0] == '+') {
			trie.insert(num);
		} else if (str[0] == '-') {
			trie.del(num);
		} else {
			printf("%d\n", trie.calc(num));
		}
	}

	return 0;
}