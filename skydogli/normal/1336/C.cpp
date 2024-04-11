#include<bits/stdc++.h>
using namespace std;
#define MN 3005
#define Mod 998244353
char S[MN],T[MN];
int f[MN][MN];
int main(){
	scanf("%s%s",S+1,T+1);
	int n=strlen(S+1),m=strlen(T+1);
	for(int i=1;i<=m;++i)f[0][i]=1;
	f[0][m+1]=1;
	long long ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m+1;++j){
			int r=j+i-1;
			if(j!=1&&S[i]==T[j-1])
				f[i][j-1]=(f[i][j-1]+f[i-1][j])%Mod;
			if(r>m){f[i][j]=(f[i][j]+f[i-1][j]*(1+(j==(m+1))))%Mod;continue;}
			if(S[i]==T[r])f[i][j]=(f[i][j]+f[i-1][j])%Mod;
		//	cerr<<"? "<<i<<" "<<j<<" "<<r<<" "<<f[i][j]<<endl;
		}
		if(i>=m)ans+=f[i][1];
//		for(int j=1;j<=m+1;++j)cerr<<i<<" "<<j<<": "<<f[i][j]<<endl;
	}
	printf("%lld\n",ans%Mod);
	return 0;
}