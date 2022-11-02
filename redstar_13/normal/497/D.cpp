#include<bits/stdc++.h>
#define eps 1e-9
#define NN 1002

typedef double DO;
using namespace std;
char gchar(){static char tbuf1[NN],*tmp_st=tbuf1,*tmp_ed=tbuf1;if(tmp_st==tmp_ed){int len=fread(tbuf1,1,NN,stdin);if(len==0)return-1;tmp_ed=tbuf1+len;tmp_st=tbuf1;}return*(tmp_st++);}
inline bool gn(int&x){char c,sg=0;while(c=gchar(),(c>'9'||c<'0')&&c!='-'&&~c);if(c==-1)return 0;for((c=='-'?sg=1,c=gchar():0),x=0;c>='0'&&c<='9';c=gchar())x=(x<<1)+(x<<3)+c-'0';if(sg)x=-x;return 1;}

struct point {
	int x, y;
	inline void input() {gn(x), gn(y);}
	point(int x=0, int y=0) : x(x), y(y) {}
	inline DO nor() {return sqrt(*this**this);}
	inline int operator * (point a) {return x*a.x+y*a.y;}
	inline int operator ^ (point a) {return x*a.y-y*a.x;}
	inline point operator - (point a) {return point(x-a.x, y-a.y);}
	inline point operator + (point a) {return point(x+a.x, y+a.y);}
};

inline DO pdist(point c, point a, point b) {
	point aa=c-a, bb=c-b, ab=a-b;
	if(aa*ab>=0) return aa.nor();
	if(bb*ab<=0) return bb.nor();
	return abs(aa^bb)/ab.nor();
}

DO r;

inline bool can(point *a, point *b, int n, int m) {
	for(int i=1; i<=n; i++) {
		point focus=b[0]+a[i]-a[0];
		for(int j=1; j<=m; j++) {
			DO pd=pdist(focus, b[j], b[j+1]);
			DO R=max((b[j]-focus).nor(), (b[j+1]-focus).nor());
			if(pd-eps<r && r<R+eps) return true;
		}
	}
	return false;
}

point a[NN], b[NN];

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	a[0].input();
	int n; gn(n);
	for(int i=1; i<=n; i++) a[i].input();
	a[n+1]=a[1];
	
	b[0].input();
	int m; gn(m);
	for(int i=1; i<=m; i++) b[i].input();
	b[m+1]=b[1];
	
	r=(a[0]-b[0]).nor();
	puts(can(a, b, n, m) || can(b, a, m, n) ? "YES" : "NO");
}