#include <cstdio>
#include <cstring>
#include <algorithm>
const int Maxn=5000;
int n;
int a[Maxn+5];
int f[Maxn+5][Maxn+5][2];
int main(){
	scanf("%d",&n);
	memset(f,0x3f,sizeof f);
	f[0][0][0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=0;j<=(n+1)/2;j++){
			f[i][j][0]=std::min(f[i-1][j][0],f[i-1][j][1]+std::max(a[i]-a[i-1]+1,0));
			if(j>0){
				f[i][j][1]=f[i-1][j-1][0]+std::max(a[i-1]-a[i]+1,0);
				if(i>1){
					f[i][j][1]=std::min(f[i][j][1],f[i-2][j-1][1]+std::max(a[i-1]-std::min(a[i-2],a[i])+1,0));
				}
			}
		}
	}
	for(int i=1;i<=(n+1)/2;i++){
		printf("%d ",std::min(f[n][i][0],f[n][i][1]));
	}
	puts("");
	return 0;
}