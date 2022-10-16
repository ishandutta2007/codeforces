#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int Maxn=200000;
const int Maxb=200;
const int Inf=0x3f3f3f3f;
int n;
int a[Maxn+5];
vector<int> lis[Maxn+5];
int sum[Maxn+5],pos[Maxn+5];
int num[Maxn<<1|5];
bool vis[Maxn+5];
int len;
int ans;
void calc(){
	if(len==0){
		return;
	}
	pos[len+1]=n+1;
	for(int i=0;i<=len;i++){
		ans=max(ans,pos[i+1]-1-num[sum[i]+Maxn]);
		num[sum[i]+Maxn]=min(num[sum[i]+Maxn],pos[i]);
	}
	for(int i=0;i<=len;i++){
		num[sum[i]+Maxn]=Inf;
	}
}
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
	for(int i=1;i<=n;i++){
		if(i==id){
			continue;
		}
		if(!lis[i].empty()&&(int)lis[i].size()<Maxb){
			len=0;
			for(int j=0;j<(int)lis[i].size();j++){
				int cur=lower_bound(lis[id].begin(),lis[id].end(),lis[i][j])-lis[id].begin();
				for(int k=max(0,cur-(int)lis[i].size()-1);k<cur;k++){
					if(!vis[k]){
						len++;
						sum[len]=sum[len-1]-1;
						pos[len]=lis[id][k];
						vis[k]=1;
					}
				}
				len++;
				sum[len]=sum[len-1]+1;
				pos[len]=lis[i][j];
				for(int k=cur;k<(int)lis[id].size()&&k<=cur+(int)lis[i].size()&&(j==(int)lis[i].size()-1||lis[id][k]<lis[i][j+1]);k++){
					if(!vis[k]){
						vis[k]=1;
						len++;
						sum[len]=sum[len-1]-1;
						pos[len]=lis[id][k];
					}
				}
			}
			calc();
			for(int j=0;j<(int)lis[i].size();j++){
				int cur=lower_bound(lis[id].begin(),lis[id].end(),lis[i][j])-lis[id].begin();
				for(int k=max(0,cur-(int)lis[i].size()-1);k<cur;k++){
					vis[k]=0;
				}
				for(int k=cur;k<(int)lis[id].size()&&k<=cur+(int)lis[i].size()&&(j==(int)lis[i].size()-1||lis[id][k]<lis[i][j+1]);k++){
					vis[k]=0;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}