#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int T;
int n, x, y;
int b[N];
int vis[N], ans[N];
vector<int> match[N];


void check() {
	map<int, int> m1, m2;
	int X = 0, Y = 0;
	for (int i = 1; i <= n; i ++) {
		if (b[i] == ans[i]) X ++;
		m1[b[i]] ++, m2[ans[i]] ++;
	}
	for (auto p: m1) {
		Y += min(m1[p.first], m2[p.first]);
	}
	//printf("x = %d, y = %d\n", x, y); 
	assert(x == X && y == Y);
}


int main() {
	scanf("%d", &T);
	while (T --) {
		scanf("%d%d%d", &n, &x, &y);
		//n = rand() % 1000 + 1, x = rand() % n + 1, y = rand() % n + 1; if (x > y) swap(x, y);
		for (int i = 0; i <= n + 1; i ++) {
			vis[i] = 0; match[i].clear(); ans[i] = 0;
		}
		//printf("input\n");
		//printf("%d %d %d\n", n, x, y);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &b[i]); 
			//b[i] = rand() % 6  +1;
			//printf("%d ", b[i]);
			vis[ b[i] ] ++;
		}
		//printf("\n");
		//printf("end\n");

		if (x == n) {
			printf("YES\n");
			for (int i = 1; i <= n; i ++) printf("%d ", b[i]);
			printf("\n");
			continue;
		}

		int bu = -1;
		for (int i = 1; i <= n + 1; i ++) {
			if (vis[i] == 0) {
				bu = i; break;
			}
		}

		set< pair<int, int> > st; st.clear();
		for (int i = 1; i <= n + 1; i ++) {
			if (vis[i]) st.insert(make_pair(vis[i], i));
		}
		// step 1: del
		for (int i = 1; i <= x; i ++) {
			pair<int, int> cur = (*st.rbegin()); 
			st.erase(cur);
			match[cur.second].push_back(cur.second);
//printf("del %d\n", cur.second);
			cur.first --;
			if (cur.first > 0) st.insert(cur);
		}
		for (int i = 1; i <= n; i ++) {
			if (match[b[i]].size() > 0) {
				ans[i] = match[b[i]].back();
//printf("ans[%d] = %d\n", i, ans[i]);
				match[b[i]].pop_back();
			}
		}

		// step 2: choose elements not match, but in ins
		vector<int> values; values.clear();
		map<int, int> mp, mp2; mp.clear(); mp2.clear();
		for (int i = 1; i <= n; i ++) {
			if (ans[i] == 0) {
				mp[b[i]] ++;
			}
		}

		int need = y - x;
		for (auto p: mp) {
			int sup = min(p.second, n - x - p.second);
			while (need > 0) {
				if (sup == 0) break;
				sup --; need --;
				values.push_back(p.first);
				mp2[p.first] ++;
			}
		} 
		if (n - y > 0) mp2[bu] = n - y;
		//for (auto p: mp2) 
		//	printf("I have %d : %d\n", p.first, p.second);
		if (need > 0) {
			printf("NO\n"); continue;
		}


		st.clear();
		for (auto p: mp2) mp[p.first] += p.second;
		for (auto p: mp) if (mp2[p.first] > 0) st.insert(make_pair(p.second, p.first));
		//for (auto p: st) printf("st %d %d\n",p.first, p.second);
		for (int i = 1; i <= n; i ++) {
			if (ans[i] == 0) {
//printf("------- takcle i = %d\n", i);
//for (auto p: st) printf("st %d %d\n",p.first, p.second);
				auto it = st.rbegin();
				if ((*it).second != b[i]) {
//printf("ok\n");
					pair<int, int> cur = *it;
					ans[i] = cur.second;
//printf("ans[%d] = %d\n", i, ans[i]);
					st.erase(cur);
					cur.first --; mp2[cur.second] --; mp[cur.second] --; 
					if (cur.first > 0 && mp2[cur.second] > 0)
						st.insert(cur);

					if (st.count(make_pair(mp[b[i]], b[i]))) {
						st.erase(make_pair(mp[b[i]], b[i]));
						mp[b[i]] --;
						if (mp[b[i]] > 0) {
							st.insert(make_pair(mp[b[i]], b[i]));
						}
					}
				} else {
//printf("gg\n");
					pair<int, int> tmp = (*st.rbegin()); st.erase(tmp);
					pair<int, int> cur = (*st.rbegin());
//printf("cur %d %d\n", cur.first, cur.second);
					st.erase(cur);
//printf("st.erase %d %d\n", cur.first, cur.second);
					ans[i] = cur.second;
//printf("ans[%d] = %d\n", i, cur.second);
					cur.first --; mp2[cur.second] --; mp[cur.second] --;
					if (cur.first > 0 && mp2[cur.second] > 0) {
						st.insert(cur);
//printf("st.insert %d %d\n", cur.first, cur.second);
					}
					//printf("try %d %d\n", mp[b[i]], b[i]);
					//for (auto p: st) printf("%d %d\n", p.first, p.second);
					st.insert(tmp);
					if (st.count(make_pair(mp[b[i]], b[i]))) {
						st.erase(make_pair(mp[b[i]], b[i]));
//printf("st.erase %d %d\n", mp[b[i]], b[i]);
						mp[b[i]] --;
						if (mp[b[i]] > 0) {
							st.insert(make_pair(mp[b[i]], b[i]));
//printf("st.insert %d %d\n", mp[b[i]], b[i]);
						}
					}
					
				}
			}
		}

		printf("YES\n");
		for (int i = 1; i <= n; i ++)
			printf("%d ", ans[i]);
		printf("\n");
		//check();
	}
}