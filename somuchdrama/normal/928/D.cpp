#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

using namespace std;
const int AL_SIZE = 26, MAXN = 4e5;

struct node {
	bool is_terminal;
	int leaves;
	int next[AL_SIZE];
	node() {
		is_terminal = false;
		leaves = 0;
		for (int i = 0; i < AL_SIZE; ++i)
			next[i] = -1;
	}
};

node bor[MAXN];
int last = 0;

int add(string s) {
	if (s.size() == 0) return 0;
	int cnt = 0, len = 0;
	int mem = s.size(), kek = 0;
	for (auto c : s) {
		if (bor[cnt].next[c - 'a'] != -1) {
			cnt = bor[cnt].next[c - 'a'];
		} else {
			last += 1;
			bor[cnt].next[c - 'a'] = last;
			cnt = last;
		}

		len++;
		if (bor[cnt].leaves == 1) mem = min(mem, len);
		if (bor[cnt].leaves == 1 && bor[cnt].is_terminal) kek = len;
	}
	if (!bor[cnt].is_terminal) { //new string
		bor[cnt].is_terminal = true;
		cnt = 0;
		for (auto c : s) {
			cnt = bor[cnt].next[c - 'a'];
			bor[cnt].leaves++;
		}
	}
	int ans = s.size();
	ans = min(ans, mem + 1 + ((int)s.size() - kek));
	return ans;
}


int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s; int ans = 0;
	while (getline(cin, s)) {
		string cnt = "";
		for (auto c : s) {
			if ('a' <= c && c <= 'z') {
				cnt += c;
			} else {
				ans += add(cnt);
				ans += 1;
				cnt.clear();
			}
		}
		ans += add(cnt);
		ans += 1;
	}
	cout << ans << '\n';
}