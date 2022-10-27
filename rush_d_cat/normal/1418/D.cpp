#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int n, q, a[N];
map<int,int> pre, nex;
set<int> st;
multiset<int> dis;
void output() {
	if (st.size() <= 1)
		printf("%d\n", 0);
	else {
		int r = *st.rbegin();
		int l = *st.begin();
		int mx = *dis.rbegin();
		printf("%d\n", r - l - mx);
	}
}
int main() {
	scanf("%d%d", &n, &q);
	//n = 100000, q = 100000;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]); 
		//a[i] = i;
		st.insert(a[i]);
	}
	sort(a + 1, a + 1 + n);

	for (int i = 1; i < n; i ++) {
		nex[a[i]] = a[i+1];
		pre[a[i+1]] = a[i];
		dis.insert(a[i+1] - a[i]);
	}
	output();
	while (q --) {
		int op, x; 
		scanf("%d%d", &op, &x);
		//x = rand() % 10000 + 1;
		//if (st.count(x)) op = 0;
		//else op = 1;

		if (st.count(x)) {
			int lef = pre[x];
			int rig = nex[x];
			if (st.count(lef)) dis.erase(dis.find(x - lef));
			if (st.count(rig)) dis.erase(dis.find(rig - x));
			if (st.count(lef) && st.count(rig)) dis.insert(rig - lef);
			if (st.count(lef)) {
				if (st.count(rig))
					nex[lef] = rig; 
				else
					nex[lef] = 0;
			}
			if (st.count(rig)) {
				if (st.count(lef))
					pre[rig] = lef;
				else
					pre[rig] = 0;
			}
			st.erase(x);
			output();
		} else {
			if (st.size() == 0) {
				st.insert(x); 
				output();
				continue;
			}
			auto it = st.lower_bound(x);
			int rig = 0, lef = 0;
			if (it != st.end()) rig = (*it);
			if (it != st.begin()) {
				-- it; lef = (*it);
			}
			if (st.count(lef) && st.count(rig)) dis.erase(dis.find(rig - lef));
			if (st.count(lef)) pre[x] = lef; else pre[x] = 0;

			if (st.count(lef)) {
				nex[lef] = x; 
				dis.insert(x - lef);
			}
			if (st.count(rig)) nex[x] = rig; else nex[x] = 0;
			if (st.count(rig)) {
				pre[rig] = x;
				dis.insert(rig - x);
			}
			st.insert(x);
			output();
		}
	}
}