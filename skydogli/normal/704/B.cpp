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
#define MN 5005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
int n,s,e,x[MN],a[MN],b[MN],c[MN],d[MN];
int f[MN][MN];
signed main(){
	n=read();s=read();e=read();
	for(int i=1;i<=n;++i)x[i]=read();
	for(int i=1;i<=n;++i)a[i]=read()+x[i];
	for(int i=1;i<=n;++i)b[i]=read()-x[i];
	for(int i=1;i<=n;++i)c[i]=read()+x[i];
	for(int i=1;i<=n;++i)d[i]=read()-x[i];
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			if(i==s){
				f[i][j]=min(f[i][j],f[i-1][j]+c[i]);//insl
				f[i][j]=min(f[i][j],f[i-1][j-1]+d[i]);//new
				continue;
			}
			if(i==e){
				f[i][j]=min(f[i][j],f[i-1][j]+a[i]);//insr
				f[i][j]=min(f[i][j],f[i-1][j-1]+b[i]);//new
				continue;
			}
			if(j>2||i<s||i<e)
				f[i][j]=min(f[i][j],f[i-1][j-1]+b[i]+d[i]);//new
			if((j>1||i<s)){//ins l
				f[i][j]=min(f[i][j],f[i-1][j]+b[i]+c[i]);
			}
			if((j>1||i<e)){//ins r
				f[i][j]=min(f[i][j],f[i-1][j]+a[i]+d[i]);
			}
			
			if(i!=e&&i!=s){//merge
				f[i][j]=min(f[i][j],f[i-1][j+1]+c[i]+a[i]);
			}	 	
		}
	}
	printf("%lld\n",f[n][1]);
	return 0;
}