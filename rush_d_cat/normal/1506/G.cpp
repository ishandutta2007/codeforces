#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
char s[N];
set<int> v[30];
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s + 1);		
		int n = strlen(s + 1);
		for (int i = 0; i < 26; i ++) v[i].clear();
		int mx[26], mn[26];
		memset(mx, -1, sizeof(mx));
		for (int i = 1; i <= n; i ++) {
			v[s[i] - 'a'].insert(i);
			mx[s[i] - 'a'] = i;
		}
		vector<int> ch;
		for (int i = 0; i < 26; i ++) if (mx[i] >= 1)
			ch.push_back(i);

		vector<bool> vis(ch.size(), 0);
		string ans = "";
		multiset<int> mxpos;
		for (auto x: ch) mxpos.insert(mx[x]);

		int las = 0;
		for (int i = 0; i < ch.size(); i ++) {
			int cnt = 0;
			for (int j = ch.size() - 1; j >= 0; j --) if (! vis[j]) {
				int pos = (*v[ch[j]].upper_bound(las));
				int mn = (*mxpos.begin());
				if (pos <= mn) {
					ans += ('a' + ch[j]);
					las = pos;
					vis[j] = 1;
					mxpos.erase(mxpos.find(mx[ch[j]]));
					break;
				}
			}
		}
		for (int i = 0; ans[i]; i ++) printf("%c", ans[i]);
		printf("\n");
	}
}