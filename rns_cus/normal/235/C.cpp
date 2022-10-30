#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;
const int C = 26;

#define L (N << 1)

struct Node {
	int link, deep, cnt;
	int nxt[C];
	void clear() {
		link = -1;
		cnt = deep = 0;
		memset(nxt, -1, sizeof(nxt));
	}
};
Node node[L];
int SZ, last;

void init() {
	node[0].clear();
	SZ = 1;
	last = 0;
}

void insert(int c) {
	int cur = SZ ++;
	node[cur].clear();
	node[cur].deep = node[last].deep + 1;

	int p = last;

	while (p != -1 && node[p].nxt[c] == -1) {
		node[p].nxt[c] = cur;
		p = node[p].link;
	}

	if (p == -1) node[cur].link = 0;
	else {
		int q = node[p].nxt[c];
		if (node[q].deep == node[p].deep + 1) node[cur].link = q;
		else {
			int clone = SZ ++;
			node[clone] = node[q];
			node[clone].deep = node[p].deep + 1;
			node[cur].link = node[q].link = clone;

			while (p != -1 && node[p].nxt[c] == q) {
				node[p].nxt[c] = clone;
				p = node[p].link;
			}
		}
	}

	last = cur;
}

int cnt[L], ord[L];

int build(string &a, int len = 0) {
	len = a.length();
	for (int i = 0; i < len; i ++) insert(a[i] - 'a');
	for (int i = 0; i <= len; i++) cnt[i] = 0;
	for (int i = 0; i < SZ; i ++) cnt[node[i].deep] ++;
	for (int i = 1; i <= len; i ++) cnt[i] += cnt[i - 1];
	for (int i = 0; i < SZ; i ++) ord[-- cnt[node[i].deep]] = i;
	int st = 0;
	for(int i = 0; i < len; i ++) {
		st = node[st].nxt[a[i]-'a'];
		node[st].cnt = 1;
	}
	for(int i = SZ - 1; i >= 0; i --) {
		int j = ord[i];
		if(node[j].link == -1) continue;
		node[node[j].link].cnt += node[j].cnt;
	}
}

string s;
int n;
int vis[L], T;

int main() {
	//freopen("in.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> s;
	init();
	build(s);
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> s;
		int len = s.length();
		++ T;
		int st = 0, ll = 0;
		long long rt = 0;
		for(int j = 0; j < 2 * len - 1; j ++) {
			int k = s[j%len] - 'a';
			while(st && node[st].nxt[k] == -1) st = node[st].link, ll = node[st].deep;
			st = node[st].nxt[k];
			if(st == -1) {
				st = ll = 0; continue;
			}
			ll ++;
			if(ll < len) continue;
			while(node[node[st].link].deep >= len) st = node[st].link, ll = node[st].deep;
			if(vis[st] == T) continue;
			vis[st] = T;
			rt += node[st].cnt;
		}
		cout << rt << endl;
	}
	return 0;
}