#include <vector>
#include <cstdio>
#include <algorithm>
const int Maxn=1000000;
const int Maxv=5000;
const int Maxw=8192;
int n;
int a[Maxn+5];
int f[Maxv+5][Maxw+5];
std::vector<int> lis[Maxv+5];
bool vis[Maxw+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		lis[a[i]].push_back(i);
	}
	f[0][0]=0;
	for(int i=1;i<Maxw;i++){
		f[0][i]=n+1;
	}
	int num=0;
	vis[0]=1;
	num++;
	for(int i=1;i<=Maxv;i++){
		for(int j=0;j<Maxw;j++){
			f[i][j]=f[i-1][j];
			int val=std::upper_bound(lis[i].begin(),lis[i].end(),f[i-1][j^i])-lis[i].begin();
			if(val>=(int)lis[i].size()){
				continue;
			}
			f[i][j]=std::min(f[i][j],lis[i][val]);
			if(!vis[j]){
				vis[j]=1;
				num++;
			}
		}
	}
	printf("%d\n",num);
	for(int i=0;i<Maxw;i++){
		if(vis[i]){
			printf("%d ",i);
		}
	}
	puts("");
	return 0;
}