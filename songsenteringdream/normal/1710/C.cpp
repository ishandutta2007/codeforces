#include<cstdio>
#include<cstring>
using namespace std;
const int o=2e5+10,MOD=998244353;
inline void ad(int&a,int b){a+=b-MOD;a+=(a>>31&MOD);}
int len,f[o][2][2][2],ans,n;char s[o];
int main(){
	scanf("%s",s+1);len=strlen(s+1);
	f[0][1][1][1]=3;
	for(int i=1;i<=len;++i) for(int x=0;x<2;++x) for(int y=0;y<2;++y) for(int z=0;z<2;++z)
		if((x^y)+(x^z)==(y^z)) for(int j=0;j<2;++j) for(int k=0;k<2;++k) for(int $=0;$<2;++$)
			if((x<=s[i]-48||!j)&&(y<=s[i]-48||!k)&&(z<=s[i]-48||!$))
				ad(f[i][j&(x==s[i]-48)][k&(y==s[i]-48)][$&(z==s[i]-48)],f[i-1][j][k][$]);
	for(int i=1;i<=len;++i) n=(n*2+s[i]-48)%MOD;
	ans=(n+1ll)*(n+1)%MOD*(n+1)%MOD;
	for(int i=0;i<2;++i) for(int j=0;j<2;++j) for(int k=0;k<2;++k) ad(ans,MOD-f[len][i][j][k]);
	ans=(ans+(n+1ll)*n*3)%MOD;
	ad(ans,(n+1)*2%MOD);
	printf("%d",ans);
	return 0;
}