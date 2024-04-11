#include<bits/stdc++.h>
using namespace std;

#define K 12

int cmp, k;
struct data {
	int sz, mn[K], mx[K];
	data() {}
	data(int *a) {
		sz = 1;
		for(int i = 1; i <= k; i ++) mn[i] = a[i], mx[i] = a[i];
	}
	void operator += (data d) {
		sz += d.sz;
		for(int i = 1; i <= k; i ++) mn[i] = min(mn[i], d.mn[i]), mx[i] = max(mx[i], d.mx[i]);
	}
	bool operator < (const data &d) const {
		if(cmp == 1) {
			for(int i = 1; i <= k; i ++) if(mn[i] < d.mx[i]) return 1;
			return 0;
		}
		if(cmp == 0) {
			for(int i = 1; i <= k; i ++) if(mx[i] > d.mn[i]) return 0;
			return 1;
		}
		return mx[1] < d.mx[1];
	}
};

int n, a[20];

int main() {
	scanf("%d%d", &n, &k);
	set <data> s;
	set <data> :: iterator ia, ib, ic;
	while(n --) {
		for(int i = 1; i <= k; i ++) scanf("%d", &a[i]);
		data d(a);
		cmp = 0;
		ia = s.lower_bound(d);
		cmp = 1;
		ib = s.lower_bound(d);
		vector <data> died;
		for(ic = ia; ic != ib; ic ++) d += *ic, died.push_back(*ic);
		cmp = 2;
		for(int i = 0; i < died.size(); i ++) s.erase(died[i]);
		s.insert(d);
		ia = s.end(); ia --;
		printf("%d\n", ia->sz);
	}
}