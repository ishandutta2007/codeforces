#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
#define MN 100005
#define Mod 1000000007
int f[1005][1005][2],n,k;
int work(int i,int k,int op){
	if(f[i][k][op])return f[i][k][op];
	if(i==n+1&&!op)return 1;
	if(i==1&&op)return 1;
	if(k==1)return 1;
	if(!op)return f[i][k][op]=(work(i+1,k,0)+work(i,k-1,1))%Mod;
	else return f[i][k][op]=(work(i-1,k,1)+work(i,k-1,0))%Mod;
}
signed main(){
	int T=read();
	while(T--){
		n=read(),k=read();
		cout<<work(1,k,0)<<endl;
		for(int i=0;i<=n+1;++i)
		for(int j=0;j<=k+1;++j)
		f[i][j][0]=f[i][j][1]=0;
	}
	return 0;
}