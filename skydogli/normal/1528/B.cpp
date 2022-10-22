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
#define MN 2000005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
#define Mod 998244353
int T,n,m;
int f[MN];
signed main(){
	n=read()<<1;
	f[0]=1;
	int tmp=0;
	for(int i=2;i<=n;i+=2){
		if(i>=4)tmp=(tmp+f[i-4])%Mod;
		f[i]=(f[i]+tmp)%Mod;
	//	for(int l=2;l<=i/2;++l){
	//		f[i]=(f[i]+f[i-l*2])%Mod;
	//	}
		for(int j=1;i*j<=n;++j){
			int l=i*j;
			f[l]=(f[l]+(j==1?f[i-2]:1))%Mod;
		}
	}
	cout<<f[n]<<endl;
	return 0;
}