#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500 + 10;
int t,n,m;
char s[N][N];
bool f[N][N], g[N][N];
int main() {
	scanf("%d", &t);
	while(t--){
    	scanf("%d%d",&n,&m);
    	for(int i=1;i<=n;i++){
    		scanf("%s",s[i]+1);
    	}
    	int ans=0;
    	memset(f,0,sizeof(f));
    	for(int i=1;i<=m;i++){
    		if(s[1][i]=='*') {
    			f[i][i]=1; ans++;
    		}
    	}

    	for(int i=2;i<=n;i++){
    		memset(g,0,sizeof(g));

    		for(int l=1;l<=m;l++){
    			bool ok=1;
    			for(int r=l;r<=m;r++){
    				if(s[i][r]!='*'){
    					ok=0; break;
    				}
    				if(l==r){
    					g[l][r]=1; ans++;
    				}else{
    					if(f[l+1][r-1]) {
    						g[l][r]=1; ans++;
    					}
    				}
    			}
    		}

    		for(int l=1;l<=m;l++)for(int r=1;r<=m;r++) f[l][r]=g[l][r];
    	}
    	printf("%d\n", ans);
    }
}