#include<bits/stdc++.h>
const int N=707,M=1000000007;
using namespace std;
int n,f[N][2],g[N][2],ans;
char S[N];
int main(){
	scanf("%s",S);
	n=strlen(S);
	for(int i=0;i<n;i++)S[i]-=48;
	for(int i=0;i<9;i++){
		memset(f,0,sizeof f);
		memset(g,0,sizeof g);
		g[0][1]=1;
		for(int j=0;j<n;j++)
		for(int k=0;k<2;k++)
		for(int l=0,r;l<=S[j]||l<10&&!k;l++)
		(g[j+1][r=k&(l==S[j])]+=g[j][k])%=M,
		f[j+1][r]=(f[j+1][r]+(l>i?10ll*f[j][k]+g[j][k]:f[j][k]))%M;
		ans=((ans+f[n][0])%M+f[n][1])%M;
	}
	printf("%d",ans);
}