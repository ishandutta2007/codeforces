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
#define mn 405
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
int n,Mod;
int f[mn][mn];
signed main(){
	n=read();Mod=read();
	f[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			f[i][j]=(f[i][j]+f[i-1][j-1]*j);
			f[i][j]=(f[i][j]+f[i-1][j]*j*2);
			if(i>=2){
				f[i][j]=(f[i][j]+f[i-2][j+1]*j*2);
				f[i][j]=(f[i][j]+f[i-2][j]*j*2);
			}
			if(i>=3)f[i][j]=(f[i][j]+f[i-3][j+1]*j);
			if(f[i][j]>=Mod)f[i][j]%=Mod;
		}
	}
	printf("%lld\n",f[n][1]);
	return 0;
}