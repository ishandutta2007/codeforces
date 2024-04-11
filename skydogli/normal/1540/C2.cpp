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
#define MN 105
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
#define Mod 1000000007
int n,b[MN],c[MN],f[MN][MN*MN],tag[MN*MN];
int lim;
map<int,int>vis;
const int inf=1e9;
signed main(){
	n=read();
	int all=1;
	for(int i=1;i<=n;++i){
		c[i]=read();
		all=all*(c[i]+1)%Mod;
	}
	for(int i=1;i<n;++i)b[i]=read();
	int q=read();
//	lim=read();
	//	f[0][0]=1;
	int mx=1e9,j=0,s=0,tot=0;
	for(int i=1;i<=n;++i){
		tot+=b[i-1];s+=tot;
		j+=c[i];
		mx=min(mx,(j-s+inf*i)/i-inf);
//		cerr<<i<<": "<<j<<" "<<s<<endl;
	}
	int lst=0;
//	cerr<<"mx: "<<mx<<endl;
	for(int lim=mx;;lim--){
		tag[0]++;tag[1]--;
		int s=0,ans=0,tot=0;
		for(int i=0;i<=n;++i){
			s+=tot;
			if(i){
				s+=b[i-1];
				tot+=b[i-1];
			}
			for(int j=0;j<=i*100;++j){
				if(j)tag[j]+=tag[j-1];
				f[i][j]=tag[j]%Mod;
			}
			for(int j=0;j<=(i)*100+1;++j)tag[j]=0;
			for(int j=0;j<=i*100;++j){
				int fk=s+lim*i;
				if(j>=fk&&f[i][j]){
					if(i==n){ans+=f[i][j];continue;}
					tag[j]+=f[i][j];
					tag[j+c[i+1]+1]+=Mod-f[i][j];
				}
			}
			if(i==n)break;
		}
//		cerr<<"ans: "<<ans<<endl;
		ans%=Mod;
		if(ans==lst)break;
		lst=ans;
//		cerr<<"? "<<lim<<" "<<ans<<" "<<lst<<endl;
		vis[lim]=ans;
	}
	while(q--){
		int x=read();
		if(vis.count(x))printf("%lld\n",vis[x]);
		else if(x>mx)puts("0");
		else printf("%lld\n",all);
	}
	//	printf("%lld\n",ans%Mod);
	return 0;
}