#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a[100005];
int d[100005];
int sum[100005];
bool visit[100005];
bool cmp(int p,int q){
	return a[p].size()<a[q].size();
}
bool cmp_2(int p,int q){
	return p>q;
}
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int s,c;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&s,&c);
		a[s].push_back(c);
	}
	for(int i=1;i<=m;i++){
		d[i]=i;
		sort(a[i].begin(),a[i].end(),cmp_2);
	}
	sort(d+1,d+1+m,cmp);
	int ans=0;
	int now=0;
	int left=1;
	for(int i=1;left<=m&&i<=n;i++){
		while(left<=m&&(int)a[d[left]].size()<i){
			if(!visit[d[left]]){
				now-=sum[d[left]];
			}
			left++;
		}
		if(left>m){
			break;
		}
		for(int j=left;j<=m;j++){
			if(visit[d[j]]){
				continue;
			}
			sum[d[j]]+=a[d[j]][i-1];
			now+=a[d[j]][i-1];
			if(sum[d[j]]<=0){
				visit[d[j]]=1;
				now-=sum[d[j]];
			}
		}
		ans=mx(ans,now);
	}
	printf("%d\n",ans);
	return 0;
}