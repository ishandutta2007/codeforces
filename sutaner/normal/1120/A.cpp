#include <bits/stdc++.h>
#define maxn 600019
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
using namespace std;

int m, k, n, s;
int a[maxn], b[maxn];
multiset<int> ss, ss2, ss3;
multiset<int> :: iterator it;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("A.in", "r", stdin);
	#endif
	scanf("%d%d%d%d", &m, &k, &n, &s);
	rep(i, 1, m) scanf("%d", &a[i]);
	rep(i, 1, s) scanf("%d", &b[i]), ss.insert(b[i]), ss3.insert(b[i]);   
	int l = 1, r = 1, now = 0, mi = m, mi2 = -1;
	while (r <= m && !ss.empty()){
		it = ss.lower_bound(a[r]);
		if (it != ss.end() && *it == a[r]) ss.erase(it);
		else ss2.insert(a[r]);
		r++;
	}
	if ((s < k && ss.empty()) || (s == k && ss.empty() && ss3.count(a[l]))) {
		if (now + max(0, r - l - k) < mi) mi = now + max(0, r - l - k), mi2 = l;
	}
	for (l = 2; l <= m; l++){
		now++;
		if (now == k) now = 0;
		it = ss2.lower_bound(a[l - 1]);
		if (it != ss2.end() && *it == a[l - 1]) ss2.erase(it);
		else ss.insert(a[l - 1]);
		while (r <= m && !ss.empty()){
			it = ss.lower_bound(a[r]);
			if (it != ss.end() && *it == a[r]) ss.erase(it);
			else ss2.insert(a[r]);
			r++;
		}
		if ((s < k && ss.empty()) || (s == k && ss.empty() && ss3.count(a[l]))) {
			if (now + max(0, r - l - k) < mi) mi = now + max(0, r - l - k), mi2 = l;
		}
	}
	if (mi2 != -1 && mi <= m - n * k) {
		printf("%d\n", mi);
		rep(i, 1, (mi2 - 1) % k) printf("%d ", i);
		mi -= (mi2 - 1) % k;
		ss.clear();
		rep(i, 1, s) ss.insert(b[i]);
		rep(i, mi2 + 1, m){
			if (!mi) break;
			it = ss.lower_bound(a[i]);
			if (it != ss.end() && *it == a[i]) ss.erase(it);
			else mi--, printf("%d ", i);
		}
	}
	else printf("-1");
	return 0;
}