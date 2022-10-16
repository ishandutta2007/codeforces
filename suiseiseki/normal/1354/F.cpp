#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int Maxn=75;
const int Inf=0x3f3f3f3f;
int n,m;
int a[Maxn+5],b[Maxn+5];
int f[Maxn+5][Maxn+5],last[Maxn+5][Maxn+5];
int id[Maxn+5];
bool chos[Maxn+5];
bool cmp(int p,int q){
	return b[p]<b[q];
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i],&b[i]);
			id[i]=i;
		}
		sort(id+1,id+1+n,cmp);
		memset(f,-0x3f,sizeof f);
		memset(last,0,sizeof last);
		memset(chos,0,sizeof chos);
		f[0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=m&&j<=i;j++){
				if(f[i-1][j]!=-Inf){
					f[i][j]=f[i-1][j]+b[id[i]]*(m-1);
					last[i][j]=0;
				}
				if(j>0){
					if(f[i-1][j-1]!=-Inf){
						if(f[i-1][j-1]+a[id[i]]+b[id[i]]*(j-1)>f[i][j]){
							f[i][j]=f[i-1][j-1]+a[id[i]]+b[id[i]]*(j-1);
							last[i][j]=1;
						}
					}
				}
			}
		}
		for(int i=n,j=m;i>0;i--){
			if(last[i][j]==1){
				chos[id[i]]=1;
				j--;
			}
		}
		printf("%d\n",m+(n-m)*2);
		int num=0;
		for(int i=1;i<=n;i++){
			if(chos[id[i]]){
				num++;
				if(num==m){
					num=id[i];
					break;
				}
				printf("%d ",id[i]);
			}
		}
		for(int i=1;i<=n;i++){
			if(!chos[i]){
				printf("%d %d ",i,-i);
			}
		}
		printf("%d\n",num);
	}
	return 0;
}