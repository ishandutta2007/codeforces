#include<bits/stdc++.h>
#define INPUT_LEN 1000

using namespace std;
typedef long long INT;
char gchar(){static char tbuf1[INPUT_LEN],*tmp_st=tbuf1,*tmp_ed=tbuf1;if(tmp_st==tmp_ed){int len=fread(tbuf1,1,INPUT_LEN,stdin);if(len==0)return-1;tmp_ed=tbuf1+len;tmp_st=tbuf1;}return*(tmp_st++);}
inline bool gn(int&x){char c,sg=0;while(c=gchar(),(c>'9'||c<'0')&&c!='-'&&~c);if(c==-1)return 0;for((c=='-'?sg=1,c=gchar():0),x=0;c>='0'&&c<='9';c=gchar())x=(x<<1)+(x<<3)+c-'0';if(sg)x=-x;return 1;}
inline void print(int x){if(x<0){putchar('-');return print(-x);}if(x<10){putchar('0'+x);return;}print(x/10);putchar(x%10+'0');}

struct point {
	int x, y;
	point(int x=0, int y=0) : x(x), y(y) {}
	inline point operator - (point a) {return point(x-a.x, y-a.y);}
	inline INT operator ^ (point a) {return (INT)x*a.y-(INT)y*a.x;}
	inline INT operator * (point a) {return (INT)x*a.x+(INT)y*a.y;}
	inline void input() {gn(x), gn(y);}
} stone[7], monster[1000];

inline bool is_on(point a, point b, point c) {
	if(a-b^b-c) return 0;
	return (a-c)*(b-c)<=0;
}

int vst[1000], runs, n, k, ans;
int f[7], st[14], nn;
vector<int> on[7][1000];

main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	gn(k), gn(n);
	for(int i=k; i--; ) stone[i].input();
	for(int i=n; i--; ) monster[i].input();
	
	for(int i=k, j, I; i--; ) {
		for(j=n; j--; ) {
			for(I=n; I--; ) if(I!=j && is_on(stone[i], monster[j], monster[I])) {
				on[i][j].push_back(I);
				if(on[i][j].size()==k) break;
			}
		}
	}
	
	for(int I=n, i, j, tar; I--; ) {
		for(i=k; i--; ) f[i]=i;
		do {
			nn=0;
			tar=I; vst[tar]=++runs;
			for(i=k; i--; ) {
				for(int x: on[f[i]][tar]) if(vst[x]!=runs) {
					st[nn++]=x;
					vst[x]=runs;
					if(nn>i) break;
				}
				if(nn>i || nn==0) break;
				tar=st[--nn];
			}
			if(!nn) {ans++; break;}
		}
		while(next_permutation(f, f+k));
	}
	print(ans);
}