#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
#define N 105
int n,m;
bool ok[N];
int ans[N],mx;
char s[N][4]; int len[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n); read(m);
	rep(i,1,n-m+1) {
		char s[7]; scanf("%s",s);
		if (s[0]=='Y') ok[i]=1;
	}
	rep(i,1,n) {
		int a=i%26; s[i][1]='A'+a; len[i]=1;
		int b=i/26; if (b>=1){s[i][2]='a'+b-1; len[i]=2;}
	}
	/*rep(i,1,n) {
		printf("%d : ",i);
		rep(j,1,len[i]) printf("%c",s[i][j]);
	printf("\n");}*/
	rep(i,1,m-1) ans[i]=(++mx);
	rep(i,m,n) {
		if (ok[i-m+1]) ans[i]=(++mx);
		else ans[i]=ans[i-m+1];
	}
	rep(i,1,n) {
		rep(j,1,len[ans[i]]) printf("%c",s[ans[i]][j]);
	printf(" ");}
	return 0;
}