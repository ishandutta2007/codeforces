#include<cstdio>
#include<cstring>
using namespace std;
const int o=1e5;
int T,n,ans;char s[o];
int main(){
	for(scanf("%d",&T);T--;ans=0){
		scanf("%s",s+1);n=strlen(s+1);
		for(int i=1;i<=n;++i) ans|=(s[i]!=s[i-1]&&s[i]!=s[i+1]);
		printf(ans?"NO\n":"YES\n");
	}
	return 0;
}