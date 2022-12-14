//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5 + 9;
int qx[Maxn],qy[Maxn];
int move[Maxn],ans[Maxn];
pair<int,int> sweep[Maxn];
int s[Maxn];
int to[Maxn];
map<int,int> mark;
int find(int v) {
	if(to[v] == v) return v;
	return to[v] = find(to[v]);
}
int main() {
	ios_base::sync_with_stdio(0);
	int n,q; cin >> n >> q;
	int p = 0;
	for(int i = 0; i < q;i++) {
		to[i] = i;
		cin >> qx[i] >> qy[i];
		char c; cin >> c; move[i] = (c == 'U');
		if(!mark[qy[i]]) sweep[p++] = make_pair(qy[i],i);
		mark[qy[i]] = 1;
	}
	sort(sweep,sweep+p);
	int t = 0;
	for(int i = 0; i < p;i++) {
		int id = sweep[i].second;
		int x = qx[id],y = qy[id];
		if(move[id] == 1) {
			while(t) {
				int tm = s[t - 1];
				if(tm > id) {
					ans[tm] = qx[tm] - x;
					t--;
				}
				else {
					ans[id] = y - qy[tm];
					break;
				}
			}
			if(!t) ans[id] = y;
		} else {
			while(t) {
				int tm = s[t - 1];
				if(id < tm) t--, to[tm] = id;
				else {
					break;
				}
			}
			s[t++] = id;
		}
	}
	for(int i = 0; i < t;i++) ans[s[i]] = qx[s[i]];
	for(int i = 0; i < q;i++) {
		cout << ans[find(i)] + qx[i] - qx[find(i)] << '\n';
	}
}