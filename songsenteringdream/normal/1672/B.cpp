#include<cstdio>
#include<cstring>
using namespace std;
int T,n;char s[1<<20];
inline void slv(){
	scanf("%s",s+1);
	if(s[n=strlen(s+1)]^'B'){printf("NO\n");return;}
	for(int i=1,j=0;i<=n;++i){
		if(s[i]=='A') ++j;
		else --j;
		if(j<0){printf("NO\n");return;}
	}
	printf("YES\n");
}
int main(){for(scanf("%d",&T);T--;slv());return 0;}