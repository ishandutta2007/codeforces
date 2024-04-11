#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
int a[15][2005];
struct Node{
	int maxn;
	int id;
	friend bool operator <(Node p,Node q){
		if(p.maxn==q.maxn){
			return p.id<q.id;
		}
		return p.maxn>q.maxn;
	}
}b[2005];
int c[1<<12|5];
int f[2][1<<12|5];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			b[i].maxn=0;
			b[i].id=i;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]>b[j].maxn){
					b[j].maxn=a[i][j];
				}
			}
		}
		sort(b+1,b+1+m);
		memset(f[0],0,sizeof f[0]);
		m=min(n,m);
		int sum;
		for(int i=1;i<=m;i++){
			memset(c,0,sizeof c);
			for(int j=0;j<(1<<n);j++){
				for(int k=1;k<=n;k++){
					sum=0;
					for(int l=1;l<=n;l++){
						if(j&(1<<(l-1))){
							sum+=a[(l+k)%n==0?n:(l+k)%n][b[i].id];
						}
					}
					c[j]=max(c[j],sum);
				}
			}
			memset(f[1],0,sizeof f[1]);
			for(int j=0;j<(1<<n);j++){
				for(int k=j;k<(1<<n);k=(k+1)|j){
					f[1][k]=max(f[1][k],f[0][j^k]+c[j]);
				}
			}
			for(int j=0;j<(1<<n);j++){
				f[0][j]=f[1][j];
			}
		}
		printf("%d\n",f[0][(1<<n)-1]);
	}
	return 0;
}