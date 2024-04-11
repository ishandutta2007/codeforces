#include<cstdio>
#include<cstring>
using namespace std;
const int o=10010;
int T,n,m;char s[o],t[o];bool z[30],f[o];
inline void slv(){
	for(int i=0;i<26;++i) z[i]=0;
	scanf("%s%s",s+1,t+1);n=strlen(s+1);m=strlen(t+1);
	for(int i=1;i<=n;++i) f[i]=0;
	for(int i=m,j=n+1;i;--i){
		for(--j;j&&s[j]-t[i];--j);
		if(!j){printf("NO\n");return;}
		else f[j]=1;
	}
	for(int i=n;i;--i)
		if(f[i]){if(z[s[i]-65]){printf("NO\n");return;}}
		else z[s[i]-65]=1;
	printf("YES\n");
}
int main(){for(scanf("%d",&T);T--;slv());return 0;}