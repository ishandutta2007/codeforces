#include<bits/stdc++.h>
using namespace std;
#define MN 500005
#define int long long
#define LL long long
#define mp make_pair
#define fir first
#define sec second
#define pii pair<int,int>
#define Mod 998244353
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
int n,m,k,sum[MN],f[MN],tag[MN],lim[MN];;
vector<pii >op[MN];
signed main(){
	n=read();k=read();m=read();
	for(int i=1;i<=m;++i){
		int l=read(),r=read(),x=read();
		op[r].push_back(mp(l,x)); 
	}
	LL ans=1;
	for(int i=0;i<k;++i){
		for(int j=1;j<=n+1;++j)sum[j]=f[j]=tag[j]=lim[j]=0;
		sum[0]=f[0]=1;
		for(int j=1;j<=n;++j){
			lim[j]=max(lim[j],lim[j-1]);
			for(int o=0;o<op[j].size();++o){
				int l=op[j][o].fir,r=j,x=op[j][o].sec;
				if((x>>i)&1)tag[l]++,tag[r+1]--;
				else lim[j+1]=max(lim[j+1],l);
			}
		}
		lim[n+1]=max(lim[n+1],lim[n]);
		for(int j=1;j<=n;++j)tag[j]+=tag[j-1];
		for(int j=1;j<=n;++j){
			if(!tag[j])
			f[j]=(sum[j-1]-(lim[j]?sum[lim[j]-1]:0)+Mod)%Mod;
			sum[j]=(sum[j-1]+f[j])%Mod;
		}
	//	cerr<<"? "<<sum[n]<<" "<<lim[n+1]<<endl;
		ans=ans*(sum[n]-(lim[n+1]?sum[lim[n+1]-1]:0)+Mod)%Mod;
	}
	printf("%lld\n",ans);
	return 0;
}