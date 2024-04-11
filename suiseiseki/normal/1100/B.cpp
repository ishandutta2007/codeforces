#include <cstdio>
#include <cstring>
#define Maxn 100000
int a[Maxn+5];
int vis[Maxn+5];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int tmp=0;
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
		if(!vis[a[i]]){
			tmp++;
			if(tmp==n){
				vis[a[i]]++;
				putchar('1');
				tmp=0;
				for(int i=1;i<=n;i++){
					vis[i]--;
					if(vis[i]>0){
						tmp++;
					}
				}
				continue;
			}
		}
		vis[a[i]]++;
		putchar('0');
	}
	puts("");
	return 0;
}