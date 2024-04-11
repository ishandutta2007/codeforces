#include <bits/stdc++.h>
#define ll long long
#define maxn 300005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
deque<int> cur[100006], fr[100005];
int idcnt = 0;
int fa[maxn];
int gfa(int a) {
	if (fa[a] == a) return a;
	return fa[a] = gfa(fa[a]);
}
void otp(vi a) {
	for (auto v : a) cout << v << ' ';
	cout << endl; 
} 
priority_queue<pi> s;
int id[maxn];
int main() {
	int n;
	const int test = 0;
	if (test) n = 3334;
	else cin >> n;
	for (int i = 1; i <= n; i++) {
		int ns;
		if (test) 
			if (i < n) ns = 3;
			else ns = 290000;
		else scanf("%d", &ns);
		for (int j = 0; j < ns; j++)
			idcnt++, 
			cur[i].pb(idcnt), 
			fr[i].pb(idcnt);
		s.push(mp(ns, i)); 
	}
	for (int i = 1; i <= idcnt; i++)
		fa[i] = i;
	while (s.size() > 1) {
		pi u1 = s.top(); s.pop();
		pi u2 = s.top(); s.pop();
	//	cout << u1.fi << ' ' << u2.fi << endl;
 		int ls = 3; // >= ls
		if (s.size()) ls = s.top().fi;
		fa[gfa(cur[u2.se].front())] = gfa(cur[u1.se].front());
		int b1 = cur[u2.se].front(), 
		b2 = 0;
		cur[u2.se].pop_front(), 
		cur[u1.se].pop_front();
		int ur = u1.fi + u2.fi, 
		tm = 1;
		while (tm < u2.fi && (ur - 2) >= ls) {
			fa[gfa(cur[u2.se].front())] = gfa(cur[u1.se].front()), 
			tm++, 
			b2 = cur[u2.se].front();
			cur[u2.se].pop_front(), 
			cur[u1.se].pop_front();
			ur -= 2;
		}
		cur[u1.se].push_front(b2);
		while(cur[u2.se].size())
			cur[u1.se].push_front(cur[u2.se].front()), 
			cur[u2.se].pop_front(); 
		cur[u1.se].pb(b1);
		s.push(mp(cur[u1.se].size(), u1.se));
	//	otp(cur[ucnt]);
	}
	int cnt = 0;
	for (int i = 1; i <= idcnt; i++)
		if (fa[i] == i) id[i] = ++cnt;
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++) {
		while (fr[i].size()) {
			printf("%d ", id[gfa(fr[i].front())]);
			fr[i].pop_front();
		}
		printf("\n");
	}
	return 0;
}