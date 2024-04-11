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
#define MN 4000005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
int T,n,m;
int f[MN],tag[MN];
signed main(){
	n=read();m=read();
	int ss=1,tmp=0;
	f[1]=1;
	for(int i=2;i<=n;++i){
		tmp+=tag[i]+1;
		f[i]=(ss+tmp)%m;
		ss=(ss+f[i])%m;
		for(int j=2;j<=i&&i*j<=n;++j){
			if(i!=j)tag[i*j]=(tag[i*j]+f[i]+f[j]-f[i-1]-f[j-1]+m+m)%m;
			else tag[i*j]=(tag[i*j]+f[i]-f[i-1]+m+m)%m;
		}
	//	for(int j=2;j*j<=i;++j){
	//		if(i%j==0){
	//			tmp=(tmp+f[i/j]-f[(i-1)/j]+m)%m;
	//			int u=i/j;
	//			if(j!=u)tmp=(tmp+f[i/u]-f[(i-1)/u]+m)%m;
	//		}
	//	}
	}
	printf("%lld\n",f[n]);
	return 0;
}