#include<bits/stdc++.h>
using namespace std;
#define MN 200005
#define LL long long
#define mp make_pair
#define fir first
#define sec second
#define pii pair<int,int>
inline void chkmax(int &a,int b){if(a<b)a=b;}
inline void chkmin(int &a,int b){if(a>b)a=b;}
inline int read(){
	   int a=0,fh=1;char c=getchar();
	   while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	   while('0'<=c&&c<='9'){
		   a=a*10+c-48;
		   c=getchar();
	   }
	   return a*fh;
}
pii a[MN];
int n;
int main(){
	scanf("%d",&n);
	if((n&1)){puts("NO");return 0;}
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i].fir,&a[i].sec);
		a[i].fir<<=1;a[i].sec<<=1;
	}
	sort(a+1,a+1+n);
	pii tmp=mp((a[1].fir+a[n].fir)/2,(a[1].sec+a[n].sec)/2);
	for(int i=2;i<=n/2;++i){
		pii T=mp((a[i].fir+a[n-i+1].fir)/2,(a[i].sec+a[n-i+1].sec)/2);
		if(T!=tmp){puts("NO");return 0;}
	}
	puts("YES");
	return 0;
}