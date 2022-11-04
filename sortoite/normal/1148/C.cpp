#include<bits/stdc++.h>
#define pb push_back
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

int n;

#define NN 303030

int p[NN], pos[NN];
vector<pii> ans;

inline void update(int x, int y) {
	swap(p[x], p[y]);
	swap(pos[p[x]], pos[p[y]]);
	ans.pb(pii(x, y));
}

inline void calc(int x, int y) {
	if(x>y) swap(x, y);
	if(y-x>=n>>1) update(x, y);
	else if(y<=n>>1) {
		update(x, n);
		update(y, n);
		update(x, n);
	}
	else if(x>n>>1) {
		update(1, x);
		update(1, y);
		update(1, x);
	}
	else {
		update(1, y), update(x, n);
		update(1, n);
		update(1, y), update(x, n);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", p+i);
		pos[p[i]]=i;
	}
	
	for(int i=1; i<=n; i++) if(pos[i]!=i) {
		calc(i, pos[i]);
	}
	printf("%d\n", ans.size());
	for(pii p: ans) printf("%d %d\n", p.x, p.y);
}