#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 300005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
int T,n,m;
int a[MN],k[MN],c[MN];
char ch[MN];
signed main(){
	T=read();
	while(T--){
		n=read();m=read();
		for(int i=1;i<=n;++i)k[i]=read();
		sort(k+1,k+1+n);
		for(int i=1;i<=m;++i)c[i]=read();
		int lst=1,ans=0;
		for(int i=n;i;--i){
			if(k[i]>=lst){ans+=c[lst++];}
			else ans+=c[k[i]];
		}
		printf("%lld\n",ans);
	}
	return 0;
}