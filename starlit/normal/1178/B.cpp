#include<bits/stdc++.h>
const int N=1000006;
using namespace std;
int n;
long long f[3][N],ans;
char S[N];
int main(){
	scanf("%s",S+1);
	n=strlen(S+1),f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++)
		f[j][i]=f[j][i-1];
		if(S[i]=='o')
		f[2][i]+=f[1][i-1];
		else if(S[i-1]=='v')
		f[1][i]+=f[0][i-2],
		ans+=f[2][i-2];
	}
	printf("%lld",ans);
}