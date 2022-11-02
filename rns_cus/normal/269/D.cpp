#include <bits/stdc++.h>

using namespace std;

#define N 100100
#define inf 2000000009

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

int t, n;
int a[N], b[N], h[N];
int id[N], f[N], vis[N];
vector <int> v[N];
piii tmp[N];

set <piii> s;
set <piii> :: iterator it;

bool cmp(int i, int j) { return h[i] < h[j]; }

int calc(int x, int y, int xx, int yy) {
	return max(0, min(y, yy) - max(x, xx));
}

int calc(int i, int j) { return calc(a[i], b[i], a[j], b[j]); }

int main() {
	scanf("%d%d",&n, &t);
	for(int i = 1; i <= n; i ++) {
		scanf("%d%d%d", h + i, a +i, b + i);
		id[i] = i;
	}
	sort(id + 1, id + n + 1, cmp);
	for(int i = 1; i <= n; i ++) {
		int j = id[i];
		if(s.empty()) {
			s.insert(piii(pii(a[j], b[j]), j));
			continue;
		}
		it = s.lower_bound(piii(pii(b[j], -inf), 0));
		if(it == s.begin()) {
			s.insert(piii(pii(a[j], b[j]), j));
			continue;
		}
		it --;
		int cnt = 0;
		while(1) {
			int k = (*it).second;
			int tp = calc((*it).first.first, (*it).first.second, a[j], b[j]);
			if(tp == 0) break;
			tmp[cnt ++] = *it;
			if(calc(j, k) == tp) v[j].push_back(k);
			if(it == s.begin()) break;
			it --;
		}
		for(int i = 0; i < cnt; i ++) {
			s.erase(tmp[i]);
			if(tmp[i].first.first < a[j]) s.insert(piii(pii(tmp[i].first.first, a[j]), tmp[i].second));
			if(tmp[i].first.second > b[j]) s.insert(piii(pii(b[j], tmp[i].first.second), tmp[i].second));
		}
		s.insert(piii(pii(a[j], b[j]), j));
	}
	int rt = 0;
	for(int i = 1; i <= n; i ++) {
		int j = id[i];
		if((int)v[j].size() == 0) {
			f[j] = b[j] - a[j]; continue;
		}
		f[j] = 0;
		for(int k = 0; k < (int)v[j].size(); k ++) {
			int tp = min(calc(j, v[j][k]), f[v[j][k]]);
			f[j] = max(f[j], tp);
			vis[v[j][k]] = 1;
		}
	}
	for(int i = 1; i <= n; i ++) if(!vis[i]) rt = max(rt, f[i]);
	cout << rt << endl;
	return 0;
}