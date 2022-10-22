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
int main(){
	int T=read();
	while(T--){
		int n=read(),m=read();
		int ans=2e9;
		for(int i=1;i<=n;++i){
			int a=read();
			if(m%a!=0)ans=min(ans,max(2,m/a+(m%a!=0)));
			else ans=min(ans,m/a);
		}
		printf("%d\n",ans);
	}
	return 0;
}