#include<bits/stdc++.h>
#define INPUT_LEN 1000
#define inf 0x3f3f3f3f
#define MM 5626
#define NN 151

using namespace std;
int dp[NN][MM], a[NN];
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
char gchar(){static char tbuf1[INPUT_LEN],*tmp_st=tbuf1,*tmp_ed=tbuf1;if(tmp_st==tmp_ed){int len=fread(tbuf1,1,INPUT_LEN,stdin);if(len==0)return-1;tmp_ed=tbuf1+len;tmp_st=tbuf1;}return*(tmp_st++);}
inline bool gn(int&x){char c,sg=0;while(c=gchar(),(c>'9'||c<'0')&&c!='-'&&~c);if(c==-1)return 0;for((c=='-'?sg=1,c=gchar():0),x=0;c>='0'&&c<='9';c=gchar())x=(x<<1)+(x<<3)+c-'0';if(sg)x=-x;return 1;}
inline void print(int x){if(x<0){putchar('-');return print(-x);}if(x<10){putchar('0'+x);return;}print(x/10);putchar(x%10+'0');}

int main() {
	int n, k, s; gn(n), gn(k), gn(s);
	for(int i=1; i<=n; i++) gn(a[i]);
	smin(s, k*(n-k));
	
	for(int i=1; i<=k; i++) for(int j=0; j<=s; j++) dp[i][j]=inf;
	for(int I=1; I<=n; I++) {
		for(int i=min(k, I); i; i--) {
			for(int j=I-i, mn=min(s, i*(I-i)); j<=mn; j++) {
				smin(dp[i][j], dp[i-1][j-I+i]+a[I]);
			}
		}
	}
	print(*min_element(dp[k], dp[k]+s+1));
}