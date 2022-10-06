#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm> 
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;

int n,l;
char s[55][55],x[55];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool ok(int a, int b, int c, int d) {
	rep(j,1,l) {
		if (s[a][b]!=s[c][d]) return 0;
		b++; if (b>l) b=1;
		d++; if (d>l) d=1;
	}
	return 1;
}
inline int getans(int p) {
	int res=0;
	rep(i,2,n) {
		bool flag=0;
		rep(j,1,l) {
			if (ok(1,p,i,j)) {flag=1;res+=j-1;break;}
		}
		if (!flag) return 1e9;
	}
	return res+p-1;
}
int main() {
	read(n);
	rep(i,1,n) {
		scanf("%s",s[i]+1); l=strlen(s[i]+1);
	}
	int ans=1e9;
	rep(i,1,l) ans=min(ans,getans(i));
	if (ans==1e9) puts("-1"); else printf("%d",ans);
	return 0;
}