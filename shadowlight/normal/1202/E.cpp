#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int INF = 1e9 + 7;
const int Q = 31;

string t;

struct TNode {
	vector <TNode*> edges;
	int cnt, len;
	TNode *link, *term_link;
};

TNode *new_node() {
	return new TNode({vector <TNode*> (Q, nullptr), 0, 0, nullptr, nullptr});
}

void add(TNode *root, string s) {
	for (char c : s) {
		int k = c - 'a';
		if (!root->edges[k]) {
			root->edges[k] = new_node();
			root->edges[k]->len = root->len + 1;
		}
		root = root->edges[k];
	}
	root->cnt++;
}

TNode *root = new_node();

void build_links() {
	queue <TNode*> q;
	q.push(root);
	root->link = root, root->term_link = root;
	while (!q.empty()) {
		TNode *now = q.front();
		q.pop();
		for (int i = 0; i < Q; i++) {
			if (!now->edges[i]) continue;
			TNode *pred = now->link;
			while (pred != root && !pred->edges[i]) {
				pred = pred->link;
			}
			if (!pred->edges[i] || pred->edges[i] == now->edges[i]) {
				now->edges[i]->link = root;
			} else {
				now->edges[i]->link = pred->edges[i];
			}
			if (now->edges[i]->link->cnt) {
				now->edges[i]->term_link = now->edges[i]->link;
			} else {
				now->edges[i]->term_link = now->edges[i]->link->term_link;
			}
			q.push(now->edges[i]);
		}
	}
}

int main() {
	//freopen("E.in", "r", stdin);
	//freopen("E.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> t;
	int n = t.size();
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		string s;
		cin >> s;
		add(root, s);
	}
	build_links();
	vector <int> dp(n + 1, 0);
	TNode *now = root;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		int k = t[i] - 'a';
		while (now != root && !now->edges[k]) {
			now = now->link;
		}
		if (now->edges[k]) {
			now = now->edges[k];
		}
		TNode *pred = now;
		dp[i - now->len + 1] += now->cnt;
		while (pred != root) {
			pred = pred->term_link;
			dp[i - pred->len + 1] += pred->cnt;
		}
	}
	/*for (int i = 0; i < n; i++) {
		cout << i << " " << dp[i] << "\n";
	}*/
	ll res = 0;
	now = root;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		int k = t[i] - 'a';
		while (now != root && !now->edges[k]) {
			now = now->link;
		}
		if (now->edges[k]) {
			now = now->edges[k];
		}
		res += now->cnt * (ll) dp[i + 1];
		TNode *pred = now;
		while (pred != root) {
			pred = pred->term_link;
			res += pred->cnt * (ll) dp[i + 1];
		}
	}
	cout << res << "\n";
}