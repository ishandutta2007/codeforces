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
int tot,lim;
signed main(){
	n=read();
	for(int i=1;i<=n;++i)c[i]=read();
	for(int i=1;i<n;++i)b[i]=read();
	int q=read();lim=read();
//	f[0][0]=1;
	tag[0]++;tag[1]--;
	int s=0,ans=0;
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
	printf("%lld\n",ans%Mod);
	return 0;
}