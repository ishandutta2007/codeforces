#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;
string line;
int n;

vector<int> sp[maxn];

struct Vertex {
	int next[26];
	int leaf = -1;
	int p = -1;
	char pch;
	int link = -1;
	int go[26];
	int mlink = -1; //match link

	Vertex (int p = -1, char ch = '$') : p(p), pch(ch) {
		fill(begin(next), end(next), -1);
		fill(begin(go), end(go), -1);
	}
};

vector<Vertex> t(1);

void add_string(string const& s, int indo) {
	int v = 0;
	for (char ch : s) {
		int c = ch-'a';
		if (t[v].next[c] == -1) {
			t[v].next[c] = t.size();
			t.emplace_back(v, ch);
		}
		v = t[v].next[c];
	}
	t[v].leaf = indo;
}

int go(int v, char ch);

int get_link(int v) {
	if (t[v].link == -1) {
		if (v == 0 || t[v].p == 0) {
			t[v].link = 0;
		}
		else {
			t[v].link = go(get_link(t[v].p), t[v].pch);
		}
	}
	return t[v].link;
}

int go(int v, char ch) {
	int c = ch-'a';
	if (t[v].go[c] == -1) {
		if (t[v].next[c] != -1) {
			t[v].go[c] = t[v].next[c];
		}
		else {
			t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
		}
	}
	return t[v].go[c];
}

int getm(int v) {
	if (t[v].mlink == -1 ) {

		if (v == 0 || t[v].link == 0) {
			t[v].mlink = 0;
		}
		else {
			if (t[t[v].link].leaf > 0) {
				t[v].mlink = t[v].link;
			}
			else t[v].mlink = getm(t[v].link);
		}

	}
	return t[v].mlink;
}

int ki[maxn];
string mi[maxn];
#define pii pair<int, int>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> line >> n;
	//build the aho on the remaining strings
	for (int i = 1; i <= n; i++) {
		cin >> ki[i] >> mi[i];
		add_string(mi[i], i);
	}

	for (int i = 0; i < t.size(); i++) {
		get_link(i);
		
	}

	
	for (int j = 0; j < t.size(); j++) {

		getm(j);
		// int i = stuff[j].second;
		// if (t[get_link(i)].leaf > 0) {
		// 	t[i].mlink = t[i].link;
		// }
		// else t[i].mlink = t[get_link(i)].mlink;
	}
	// cout << "here " << endl;

	//need to store link to the previous link

	int cspot = 0;

	for (int i = 0; i < line.length(); i++) {
		cspot = go(cspot, line[i]);

		int cur = cspot;
		while (cur != 0 && cur != -1) {
			// cout << "cur -- " << cur << endl;
			if (t[cur].leaf > 0) {
				sp[t[cur].leaf].push_back(i);
			}
			cur = t[cur].mlink;
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	cout << mi[i] << ": ";
	// 	for (int v : sp[i]) cout << v << " ";
	// 	cout << endl;
	// }
	for (int i = 1; i <= n; i++) {
		int res = -1;
		for (int j = ki[i]-1; j < sp[i].size(); j++) {
			int cv = sp[i][j] - sp[i][j-(ki[i]-1)] + mi[i].length();
			if (res == -1 || res > cv) res = cv;
		}
		cout << res << '\n';
	}
	cout.flush();

}