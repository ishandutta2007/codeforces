#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <map>
#include <set>

#define maxn 100500

using namespace std;

struct list {
	long long x;
	int y;
	int sum;
	int cnt;
	int l, r;
} sm[maxn];

int num;
int n;
long long k;
long long a[maxn];

inline int upd (int t) {
	sm[t].sum = sm[sm[t].l].sum + sm[sm[t].r].sum + sm[t].cnt;
	return 0;
}

int search (int t, long long x) {
	while (t && sm[t].x != x)
		t = (sm[t].x > x) ? sm[t].l : sm[t].r;
	return t;
}

int split (int t, long long x, int &a, int &b) {
	if (!t) {
		a = b = 0;
		return 0;
	} else {
		int ca, cb;
		if (sm[t].x < x) {
			split (sm[t].r, x, ca, b);
			sm[t].r = ca;
			a = t;
			upd (t);
			return 0;
		} else {
			split (sm[t].l, x, a, cb);
			sm[t].l = cb;
			b = t;
			upd (t);
			return 0;
		}
	}
	return 0;
}

int merge_tree (int t1, int t2) {
	int t;
	if (!t1) return t2;
	if (!t2) return t1;
	if (sm[t1].y < sm[t2].y) {
		sm[t1].r = merge_tree (sm[t1].r, t2);
		t = t1;
	} else {
		sm[t2].l = merge_tree (t1, sm[t2].l);
		t = t2;
	}
	upd(t);
	return t;
}

int add (long long x, int root) {
	int cur = search (root, x);
	int tmp = root;
	if (cur) {
		while (sm[tmp].x != x) {
			++sm[tmp].sum;
			tmp = (sm[tmp].x > x) ? sm[tmp].l : sm[tmp].r;
		}
		++sm[cur].cnt;
		upd (cur);
	} else {
		int aa, b, c;
		split (root, x, aa, b);
		//printf ("root = %d, aa = %d, b = %d\n", root, aa, b);
		++num;
		sm[num].x = x;
		sm[num].l = sm[num].r = 0;
		sm[num].cnt = sm[num].sum = 1;
		sm[num].y = rand ();
		c = merge_tree (aa, num);
		root = merge_tree (c, b);
	}
	return root;
}

int num_elem (int t, long long x) {
	int ans = 0;
	while (t) {
		if (2 * sm[t].x > x) {
			ans += sm[sm[t].r].sum + sm[t].cnt;
			t = sm[t].l;
		} else 
			t = sm[t].r;
	}	
	return ans;
}

int print_tree (int x) {
	if (x) {
		print_tree (sm[x].l);
		printf ("%lld ", sm[x].x);
		print_tree (sm[x].r);
	}
	return 0;
}

int pr (int root) {
	printf ("tree is:\n");
	print_tree (root);
	printf ("\n");
	return 0;
}

long long cnt (long long x) {
	long long ans = 0;
	num = 0;
	int root = 0;
	for (int i = n; i >= 1; --i) {
		root = add (a[i], root);
		//pr (root);
		ans += num_elem (root, 2 * (x + a[i - 1]) - 1);
		//printf ("ans = %lld\n", ans);
	}
	//cout << "x = " << x << " ans = " << ans << endl;
	return ans;
}

int main () {
	int x = time (NULL);
	srand (x);
	ios_base::sync_with_stdio (false);
	cin >> n >> k;
	a[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	long long l = -1000000000000000LL,
		 	  r = 1000000000000000LL,
			  m;
	//long long l = -10, r = 10, m;
	//cerr << l << " " << r << endl;
	while (l < r - 1) {
		m = (l + r) / 2;
		if (cnt (m) >= k)
			l = m;
		else
			r = m;
		//cerr << l << " " << r << endl;
	}
	cout << l << endl;
	return 0;
}