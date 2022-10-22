#include<bits/stdc++.h>
using namespace std;
#define Mod 1000000007
#define int long long
#define MN 3005
char ch[MN][MN];
int sum[MN][MN];
int n,m;
int work(int a,int b,int c,int d){
	if(ch[a][b]=='#'||ch[c][d]=='#')return 0;
	memset(sum,0,sizeof(sum));
	sum[a][b]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
				if(ch[i][j]!='#')sum[i][j]=(sum[i-1][j]+sum[i][j-1]+sum[i][j])%Mod;
//				cerr<<i<<" "<<j<<": "<<sum[i][j]<<endl;
		}
//	cerr<<"work: "<<sum[c][d]<<endl;
	return sum[c][d];
}
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)scanf("%s",ch[i]+1);
	printf("%lld",(work(1,2,n-1,m)*work(2,1,n,m-1)-work(1,2,n,m-1)*work(2,1,n-1,m)%Mod+Mod)%Mod);
	return 0;
}