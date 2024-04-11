#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

struct Trie {
	string w;
	array<Trie*, 26> ch;
	Trie() : ch() {}
	Trie* traverse(char c);
};

Trie* Trie::traverse(char c) {
	int d = c - 'a';
	if (ch[d]) return ch[d];
	return ch[d] = new Trie;
}

int main() {
	cin.sync_with_stdio(false);
	int N, M;
	cin >> N;
	string text;
	cin >> text;
	cin >> M;
	string w;
	Trie* tr = new Trie;
	rep(i,0,M) {
		Trie* t = tr;
		cin >> w;
		reverse(all(w));
		trav(c, w) {
			char d = (char)tolower(c);
			t = t->traverse(d);
		}
		reverse(all(w));
		t->w = w;
	}

	vector<string*> solw(N+1);
	vector<int> sol(N+1, -1);
	sol[0] = -2;
	rep(i,0,N) {
		if (sol[i] == -1) continue;
		Trie* t = tr;
		rep(j,i+1,N+1) {
			int d = text[j-1] - 'a';
			if (!t->ch[d]) break;
			t = t->ch[d];
			if (!t->w.empty()) {
				sol[j] = i;
				solw[j] = &t->w;
			}
		}
	}
	assert(sol[N] != -1);
	vector<string*> res;
	int at = N;
	while (sol[at] != -2) {
		res.push_back(solw[at]);
		at = sol[at];
	}
	reverse(all(res));
	trav(x, res) cout << *x << ' ';
	cout << endl;
}