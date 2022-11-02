#include<bits/stdc++.h>
#define INPUT_LEN 1000
#define NN 200000
#define MM 49

typedef double DO;
using namespace std;
char gchar(){static char tbuf1[INPUT_LEN],*tmp_st=tbuf1,*tmp_ed=tbuf1;if(tmp_st==tmp_ed){int len=fread(tbuf1,1,INPUT_LEN,stdin);if(len==0)return-1;tmp_ed=tbuf1+len;tmp_st=tbuf1;}return*(tmp_st++);}
inline bool gn(int&x){char c,sg=0;while(c=gchar(),(c>'9'||c<'0')&&c!='-'&&~c);if(c==-1)return 0;for((c=='-'?sg=1,c=gchar():0),x=0;c>='0'&&c<='9';c=gchar())x=(x<<1)+(x<<3)+c-'0';if(sg)x=-x;return 1;}

struct point {
	int x, y;
	inline void input() {gn(x), gn(y);}
	point(int x=0, int y=0) : x(x), y(y) {}
	inline DO operator ^ (point a) {return (DO)x*a.y-(DO)y*a.x;}
	inline point operator - (point a) {return point(x-a.x, y-a.y);}
};

point p[NN];
DO f[MM]={1};

int main() {
	int n; gn(n);
	for(int i=0; i<n; i++) p[i].input(), p[n+i]=p[i];
	for(int i=1; i<MM; i++) f[i]=f[i-1]+f[i-1];
	
	DO ans=0, plan, pro, sum, cnt, S;
	if(n<MM) plan=f[n]-1-n-(n*(n-1)>>1);
	
	for(int i=0; i<n; i++) {
		ans+=p[i]-p[0]^p[i+1]-p[0];
		ans-=abs(__gcd(p[i].x-p[i+1].x, p[i].y-p[i+1].y));
	}
	ans=ans/2+1;
	
	for(int i=0; i<n; i++) {
		pro=.25, sum=0;
		cnt=abs(__gcd(p[i+1].x-p[i].x, p[i+1].y-p[i].y));
		for(int j=3; j<n; j++) {
			if(n<MM) pro=(f[n-j]-1)/plan;
			else pro/=2;
			
			if(pro<1e-11) break;
			
			sum+=p[i+j-2]-p[i]^p[i+j-1]-p[i];
			cnt+=abs(__gcd(p[i+j-2].x-p[i+j-1].x, p[i+j-2].y-p[i+j-1].y));
			
			S=sum-cnt+abs(__gcd(p[i+j-1].x-p[i].x, p[i+j-1].y-p[i].y));
			ans-=pro*S/2;
		}
	}
	printf("%.9lf", ans);
}