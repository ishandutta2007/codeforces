#include <cstdio>
#include <cstring>
#define Inf 0x3f3f3f3f
int f[105][105][30];
int val[30][30];
char s[105];
char a[5],b[5];
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int n,k,m;
	scanf("%s",s+1);
	n=0;
	while(s[++n]!='\0');
	n--;
	scanf("%d",&k);
	scanf("%d",&m);
	int v;
	for(int i=1;i<=m;i++){
		scanf("%s%s",a,b);
		scanf("%d",&v);
		val[(*a)-'a'][(*b)-'a']=v;
	}
	memset(f,-0x3f,sizeof f);
	f[0][0][26]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i&&j<=k;j++){
			for(int l=0;l<=26;l++){
				if(j>0&&f[i-1][j-1][l]!=-Inf){
					for(int x=0;x<26;x++){
						if(x==(s[i]-'a')){
							continue;
						}
						f[i][j][x]=mx(f[i][j][x],f[i-1][j-1][l]+val[l][x]);
					}
				}
				if(f[i-1][j][l]!=-Inf){
					f[i][j][s[i]-'a']=mx(f[i][j][s[i]-'a'],f[i-1][j][l]+val[l][s[i]-'a']);
				}
			}
		}
	}
	int ans=-Inf;
	for(int i=0;i<=k;i++){
		for(int j=0;j<26;j++){
			ans=mx(ans,f[n][i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}