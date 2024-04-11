#include<bits/stdc++.h>

#define x first
#define y second
using namespace std;
using INT = long long;
using pii = pair<int, int>;

int n;
const int NN = 400011;
pii p[NN];
int nxt[NN];
int ans = 0;
map<pii, int> mp;
int flag[NN];

void up(int &now, int x) {
	int y = nxt[x];
	flag[x] = flag[y] = 1;
	now += mp[{x, y}];	
}

void bad() {
	puts("-1");
	exit(0);
}

void solve(int st, int ed) {
	if(st > ed) return ;
	if(nxt[st] == ed) return solve(st + 1, ed - 1);
	int a = nxt[st];
	int b = nxt[ed];
	int now = 0;
	int nn ;
	int A = nxt[st], B = nxt[ed];
	if(A < B) bad();
	flag[st] = flag[ed] = 1;
	nn = 2;
	up(now, st);
	up(now, ed);
	while(1) {
		int ok = 0;
		for(int i=st; i<b; i++) if(flag[i] == 0) {
			int x = nxt[i];
			if(x > A) bad();
			ok = 1;
			A = x;
			up(now, i);
			st = i;
			nn++;
		}
		for(int i=ed; i>a; i--) if(flag[i] == 0) {
			int x = nxt[i];
			if(x < B) bad();
			ok = 1;
			B = x;
			up(now, i);
			ed = i;
			nn++;
		}
		if(ok == 0) break;
//		cerr<<st<<' '<<ed<<endl;
		a = nxt[st];
		b = nxt[ed];
		if(a < b) bad();
	}
//	cerr << now << ' ' << nn << endl;
	ans += min(now, nn - now);
	return solve(b + 1, a - 1);	
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	cin >> n;

	for(int i=0; i<n; i++) {
		scanf("%d %d", &p[i].x, &p[i].y);
		nxt[p[i].x] = p[i].y;
		nxt[p[i].y] = p[i].x;
		mp[{p[i].x, p[i].y}] = 1;
	}
	sort(p, p+n);	
	solve(1, 2*n);
	cout << ans << endl;

	return 0;
}