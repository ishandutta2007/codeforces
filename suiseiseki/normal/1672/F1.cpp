#include <vector>
#include <cstdio>
#include <algorithm>
const int Maxn=200000;
int n;
int a[Maxn+5];
int b[Maxn+5];
std::vector<int> lis[Maxn+5];
int num[Maxn+5],id[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		lis[i].clear();
		id[i]=i,num[i]=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
		lis[a[i]].push_back(i);
		num[a[i]]++;
	}
	std::sort(id+1,id+1+n,[&](int p,int q){return num[p]>num[q];});
	for(int i=2;i<=n;i++){
		for(int j=0;j<(int)lis[id[i]].size();j++){
			std::swap(b[lis[id[i]][j]],b[lis[id[i-1]][j]]);
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",b[i]);
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}