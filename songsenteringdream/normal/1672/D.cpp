#include<cstdio>
using namespace std;
const int o=2e5+10;
int T,n,a[o],b[o],z[o];
inline void slv(){
	scanf("%d",&n);a[n+1]=0;
	for(int i=1;i<=n;++i) z[i]=0,scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	for(int i=1,j=1;i<=n;++i)
		if(b[i]==a[j-1]&&z[b[i]]) --z[b[i]];
		else if(b[i]==a[j]) ++j;
		else{
			for(;j<=n&&b[i]-a[j];++z[a[j++]]);
			if((j++)>n){printf("NO\n");return;}
		}
	printf("YES\n");
}
int main(){for(scanf("%d",&T);T--;slv());return 0;}