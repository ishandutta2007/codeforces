#include <cstdio>
#include <cstring>
#include <algorithm>
const int Maxn=6;
const int Maxs=15625;
const int Inf=0x3f3f3f3f;
int n,m;
int c[Maxn+5][Maxn+5];
int f[Maxn+5][Maxs+5];
int a[Maxn+5],b[Maxn+5];
int tmp_a[Maxn+5],pos[Maxn+5];
void work_dfs(int u,int id,int val,int *f){
	int mask=0;
	for(int i=n-1;i>=0;i--){
		mask=mask*5+tmp_a[i];
	}
	f[mask]=std::min(f[mask],val);
	if(u==b[id]){
		return;
	}
	for(int i=(u==0?0:pos[u-1]);i<n;i++){
		pos[u]=i;
		tmp_a[i]++;
		if(tmp_a[i]>a[i]){
			tmp_a[i]--;
			continue;
		}
		work_dfs(u+1,id,val+((u==0||pos[u]!=pos[u-1])?c[i][id]:0),f);
		tmp_a[i]--;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	int max_mask=1;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		max_mask=max_mask*5;
	}
	for(int i=0;i<m;i++){
		scanf("%d",&b[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&c[i][j]);
		}
	}
	memset(f,0x3f,sizeof f);
	f[0][0]=0;
	for(int i=0;i<m;i++){
		for(int mask=0;mask<max_mask;mask++){
			if(f[i][mask]>=Inf){
				continue;
			}
			bool flag=1;
			for(int j=0,tmp=mask;j<n;j++){
				tmp_a[j]=tmp%5;
				tmp/=5;
				if(tmp_a[j]>a[j]){
					flag=0;
					break;
				}
			}
			if(!flag){
				continue;
			}
			work_dfs(0,i,f[i][mask],f[i+1]);
		}
	}
	int mask=0;
	for(int i=n-1;i>=0;i--){
		mask=mask*5+a[i];
	}
	if(f[m][mask]>=Inf){
		puts("-1");
	}
	else{
		printf("%d\n",f[m][mask]);
	}
	return 0;
}