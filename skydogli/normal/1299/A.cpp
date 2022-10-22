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
int n,a[MN],vis[35];
int main(){
	scanf("%d",&n);
	int s=0,tot=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		for(int j=0;j<=30;++j)
			if(a[i]&(1<<j))vis[j]++;
	}
	for(int i=30;i>=0;--i){
		if(vis[i]==1){
			for(int j=1;j<=n;++j)if((a[j]&(1<<i)))printf("%d ",a[j]);
			for(int j=1;j<=n;++j)
				if(!(a[j]&(1<<i)))printf("%d ",a[j]);
			return 0;
		}
	}
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	return 0;
}