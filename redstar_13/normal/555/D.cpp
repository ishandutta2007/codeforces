#include<bits/stdc++.h>
#define INPUT_LEN 1000
#define NN 200001
#define y second
#define x first

using namespace std;
typedef pair<int, int> pii;
char gchar(){static char tbuf1[INPUT_LEN],*tmp_st=tbuf1,*tmp_ed=tbuf1;if(tmp_st==tmp_ed){int len=fread(tbuf1,1,INPUT_LEN,stdin);if(len==0)return-1;tmp_ed=tbuf1+len;tmp_st=tbuf1;}return*(tmp_st++);}
inline bool gn(int&x){char c,sg=0;while(c=gchar(),(c>'9'||c<'0')&&c!='-'&&~c);if(c==-1)return 0;for((c=='-'?sg=1,c=gchar():0),x=0;c>='0'&&c<='9';c=gchar())x=(x<<1)+(x<<3)+c-'0';if(sg)x=-x;return 1;}
inline void print(int x){if(x<0){putchar('-');return print(-x);}if(x<10){putchar('0'+x);return;}print(x/10);putchar(x%10+'0');}

pii p[NN];
int pos[NN];

main() {
	int n, m, id, L, nxt, pre, t, len;
	gn(n), gn(m);
	for(int i=1; i<=n; i++) gn(p[i].x), p[i].y=i;
	sort(p+1, p+n+1);
	for(int i=1; i<=n; i++) pos[p[i].y]=i;
	
	while(m--) {
		gn(id), gn(L); id=pos[id];
		pre=0, t=1;
		while(1) {
			if(t) {
				nxt=upper_bound(p+1, p+n+1, pii(p[id].x+L, n))-p-1;
				len=p[nxt].x-p[id].x;
			}
			else {
				nxt=lower_bound(p+1, p+n+1, pii(p[id].x-L, 0))-p;
				len=p[id].x-p[nxt].x;
			}
			L-=len;
			if(pre==nxt) {
				if(id==nxt) break;
				if(len) L%=(len<<1);
			}
			pre=id, id=nxt;
			t^=1;
		}
		print(p[id].y); putchar('\n');
	}
}