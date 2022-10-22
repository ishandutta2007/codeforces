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
    vi vec[2];
    Trie *next[26];

    Trie() {
	fill(next, next + 26, (Trie*)0);
    }
};

Trie *add(string &t, Trie *r, bool f, int id)
{
    for (char cc : t) {
	int c = cc - 'a';
	if (!r->next[c]) r->next[c] = new Trie;
	r = r->next[c];
    }

    r->vec[f].pb(id);

    return r;
}

int n;
ll sum;
vector<pii> ans;

void dfs(Trie *r, int dep)
{
    rep(i, 26) {
	if (r->next[i]) {
	    dfs(r->next[i], dep + 1);
	    r->vec[0].insert(r->vec[0].end(), ALL(r->next[i]->vec[0]));
	    r->vec[1].insert(r->vec[1].end(), ALL(r->next[i]->vec[1]));
	}
    }

    while (r->vec[0].size() && r->vec[1].size()) {
	sum += dep;
	ans.eb(r->vec[0].back(), r->vec[1].back());
	r->vec[0].pop_back();
	r->vec[1].pop_back();
    }    
}

int main() {
    cin >> n;

    Trie *root = new Trie;

    rep(i, n) {
	string s;
	cin >> s;
	add(s, root, 0, i);
    }

    rep(i, n) {
	string s;
	cin >> s;
	add(s, root, 1, i);
    }

    dfs(root, 0);

    cout << sum << endl;
    rep(i, n) cout << ans[i].fi + 1 << " " << ans[i].se + 1 << endl;

    return 0;
}