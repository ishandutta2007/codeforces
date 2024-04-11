#include<bits/stdc++.h>
#define INPUT_LEN 1000
#define MM 400000
#define NN 61

using namespace std;
char gchar(){static char tbuf1[INPUT_LEN],*tmp_st=tbuf1,*tmp_ed=tbuf1;if(tmp_st==tmp_ed){int len=fread(tbuf1,1,INPUT_LEN,stdin);if(len==0)return-1;tmp_ed=tbuf1+len;tmp_st=tbuf1;}return*(tmp_st++);}
inline bool gn(int&x){char c,sg=0;while(c=gchar(),(c>'9'||c<'0')&&c!='-'&&~c);if(c==-1)return 0;for((c=='-'?sg=1,c=gchar():0),x=0;c>='0'&&c<='9';c=gchar())x=(x<<1)+(x<<3)+c-'0';if(sg)x=-x;return 1;}
inline bool gn(char&x){while(x=gchar(),~x&&isspace(x));return ~x;}
inline void print(int x){if(x<0){putchar('-');return print(-x);}if(x<10){putchar('0'+x);return;}print(x/10);putchar(x%10+'0');}
template<class T>inline void println(T x){print(x);putchar('\n');}

int LL[MM], RR[MM], l, r, x;
int mn_time[MM][NN];

inline void push_up(int u, int ls, int rs) {
	for(int i=NN; i--; ) {
		int L_time=mn_time[ls][i];
		mn_time[u][i] = L_time + mn_time[rs][(i+L_time)%60];
	}
}

inline void build(int u, int L, int R) {
	LL[u]=L, RR[u]=R;
	if(L+1==R) {
		gn(x);
		for(int i=NN; i--; ) mn_time[u][i]=i%x ? 1 : 2;
		return ;
	}
	int ls=u<<1, rs=ls|1, mid=L+R>>1;
	build(ls, L, mid);
	build(rs, mid, R);
	push_up(u, ls, rs);
}

inline void replace(int u) {
	int L=LL[u], R=RR[u];
	if(r<=L || R<=l) return ;
	if(l<=L && R<=r) {
		for(int i=NN; i--; ) mn_time[u][i]=i%x ? 1 : 2;
		return ;
	}
	int ls=u<<1, rs=ls|1;
	replace(ls), replace(rs);
	push_up(u, ls, rs);
}

int ans;

inline void calc(int u) {
	int L=LL[u], R=RR[u];
	if(r<=L || R<=l) return ;
	if(l<=L && R<=r) {
		ans+=mn_time[u][ans%60];
		return ;
	}
	int ls=u<<1;
	calc(ls), calc(ls|1);
}

int main() {
	int n; gn(n);
	build(1, 1, n+1);
	
	char c; gn(n);
	while(n--) {
		gn(c);
		if(c=='A') {
			gn(l), gn(r);
			ans=0; calc(1);
			println(ans);
		}
		else {
			gn(l), gn(x);
			r=l+1;
			replace(1);
		}
	}
}