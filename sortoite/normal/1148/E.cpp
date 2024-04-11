#include<bits/stdc++.h>
#define pb push_back
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<INT, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

#define NN 303030

pii p[NN];
INT t[NN];

struct data {
	int x, y; INT d;
	inline data(int x=0, int y=0, INT d=0) : x(x), y(y), d(d) {}
};

vector<data> ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%I64d", &p[i].x), p[i].y=i;
	for(int i=1; i<=n; i++) scanf("%I64d", t+i);
	sort(p+1, p+n+1), sort(t+1, t+n+1);
	
	for(int i=1; i<=n; i++) p[i].x-=t[i];
	INT sum=0;
	for(int i=1; i<=n; i++) sum+=p[i].x;
	if(sum) return puts("NO");
	
	for(int i=1, j=1; i<=n; ) {
		for(; j<=n && p[j].x<=0; j++);
		if(p[i].x==0) i++;
		else if(p[i].x>0) return puts("NO");
		else {
			if(j==n+1) return puts("NO");
			INT mn=min(-p[i].x, p[j].x);
			ans.pb(data(p[i].y, p[j].y, mn));
			p[i].x+=mn, p[j].x-=mn;
			if(p[i].x) continue;
			i++;
		}
	}
	puts("YES");
	printf("%d\n", ans.size());
	for(data p: ans) printf("%d %d %I64d\n", p.x, p.y, p.d);
}