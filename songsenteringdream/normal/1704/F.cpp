#include<cstdio>
using namespace std;
const int o=5e5+10;
int T,n,c[200],sg[o],z;bool vis[o];char s[o];
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%s",&n,s+1);c['R']=c['B']=0;
		for(int i=1;i<=n;++i) ++c[s[i]];
		if(c['R']>c['B']) printf("Alice\n");
		else if(c['R']<c['B']) printf("Bob\n");
		else{
			z=0;
			for(int i=2;i<=n;++i)
				if(i<100){
					for(int j=0;j<=i;++j) vis[j]=0;
					for(int j=0;j<i-1;++j) vis[sg[j]^sg[i-j-2]]=1;
					for(sg[i]=0;vis[sg[i]];++sg[i]);
				}
				else sg[i]=sg[i-34];
			for(int i=1,j;i<=n;++i,z^=sg[j]) for(j=1;i<n&&s[i+1]!=s[i];++i,++j);
			printf(z?"Alice\n":"Bob\n");
		}
	}
	return 0;
}