#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int n,m;
long long ans;
int f[2010][2010];
char s[2010][2010];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) scanf("%s",s[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			if(s[i][j]==s[i-1][j-1]&&s[i][j]==s[i-1][j]&&s[i][j]==s[i-1][j+1]){
				f[i][j]=min(f[i-1][j],min(f[i-1][j-1],f[i-1][j+1]));
				if(s[i-f[i][j]-f[i][j]][j]==s[i][j]) ++f[i][j];
			}
			else f[i][j]=1;
			ans+=f[i][j];
		}
	printf("%lld\n",ans);
	return 0;
}