#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

struct Trie {
	int val;
	Trie *next[2];
	Trie() { val = 0; fill(next, next+2, (Trie*)0); }
};

int q;

int main() {
	scanf("%d", &q);
	Trie* r = new Trie();

	while (q--) {
		char c[2], in[20];

		scanf("%s %s", c, in);
		string s = in;
		reverse(ALL(s));
		while (s.size() < 18) s.push_back('0');

		Trie* v = r;

		int tp;

		if (c[0] == '+') tp = 1;
		else if (c[0] == '-') tp = -1;
		else tp = 0;

		if (tp != 0) {
			rep(i, s.size()) {
				int c = (s[i]-'0') & 1;
				if (!v->next[c]) v->next[c] = new Trie;
				v = v->next[c];
				v->val += tp;		
			}
		} else {
			int ret=0;
			bool ok=1;
			rep(i, s.size()) {
				int c = s[i]-'0';
				if (!v->next[c]) {
					ok = 0;
					break;
				}
				v = v->next[c];
			}
			if (ok) ret = v->val;
			printf("%d\n", ret);
		}

	}
	return 0;
}