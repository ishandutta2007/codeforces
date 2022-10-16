#include <cstdio>
#include <vector>
#include <algorithm>
const int Maxn=500;
int n,k;
int query(std::vector<int> x){
	printf("?");
	for(int i=0;i<(int)x.size();i++){
		printf(" %d",x[i]);
	}
	puts("");
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int a[Maxn+5];
int id[Maxn+5];
bool cmp_a(int p,int q){
	return a[p]>a[q];
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=500;i++){
		if(((i*k)&1)!=(n&1)||i*k<n){
			continue;
		}
		int val=i*k/n;
		if(!(val&1)){
			val--;
		}
		int sum=0;
		for(int j=1;j<=n;j++){
			a[j]=val;
			sum+=a[j];
		}
		int pos=1;
		while(sum<i*k){
			a[pos]+=2;
			pos=pos%n+1;
			sum+=2;
		}
		if(a[1]>i){
			continue;
		}
		int ans=0;
		while(sum>0){
			for(int j=1;j<=n;j++){
				id[j]=j;
			}
			std::sort(id+1,id+1+n,cmp_a);
			std::vector<int> lis;
			for(int j=1;j<=k;j++){
				a[id[j]]--;
				lis.push_back(id[j]);
			}
			ans^=query(lis);
			sum-=k;
		}
		printf("! %d\n",ans);
		fflush(stdout);
		return 0;
	}
	puts("-1");
	fflush(stdout);
	return 0;
}