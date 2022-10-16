#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int Maxn=200000;
const int Maxb=1;
const int Inf=0x3f3f3f3f;
int n;
int a[Maxn+5];
vector<int> lis[Maxn+5];
int sum[Maxn+5];
int num[Maxn<<1|5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		lis[a[i]].push_back(i);
	}
	int sz=0,id=0;
	for(int i=1;i<=n;i++){
		if((int)lis[i].size()==sz){
			id=-1;
		}
		else if((int)lis[i].size()>sz){
			sz=lis[i].size();
			id=i;
		}
	}
	if(id==-1){
		printf("%d\n",n);
		return 0;
	}
	memset(num,0x3f,sizeof num);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(i==id){
			continue;
		}
		if((int)lis[i].size()>=Maxb){
			num[0+Maxn]=0;
			for(int j=1;j<=n;j++){
				sum[j]=sum[j-1];
				if(a[j]==id){
					sum[j]++;
				}
				if(a[j]==i){
					sum[j]--;
				}
				ans=max(ans,j-num[sum[j]+Maxn]);
				num[sum[j]+Maxn]=min(num[sum[j]+Maxn],j);
			}
			for(int j=0;j<=n;j++){
				num[sum[j]+Maxn]=Inf;
				sum[j]=0;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}