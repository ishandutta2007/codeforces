#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxk 15
#define Maxn 5000
#define ll long long
int a[Maxk+5][Maxn+5];
int n[Maxk+5];
ll sum[Maxk+5],Sum;
vector<pair<int,int> > d[(1<<Maxk)|5],tmp;
bool vis[Maxk+5];
bool f[(1<<Maxk)|5];
int g[(1<<Maxk)|5];
int ans[Maxk+5][2];
struct Node{
	int x;
	int i,j;
	friend bool operator <(Node p,Node q){
		return p.x<q.x;
	}
}b[Maxk*Maxn+5];
int len;
int k;
int find(ll x){
	int left=1,right=len,mid;
	while(left<right){
		mid=(left+right)>>1;
		if(b[mid].x<x){
			left=mid+1;
		}
		else{
			right=mid;
		}
	}
	if(b[left].x!=x){
		return -1;
	}
	return left;
}
int main(){
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&n[i]);
		for(int j=1;j<=n[i];j++){
			scanf("%d",&a[i][j]);
			b[++len].x=a[i][j];
			b[len].i=i;
			b[len].j=j;
			Sum+=a[i][j];
			sum[i]+=a[i][j];
		}
	}
	if(Sum%k){
		puts("No");
		return 0;
	}
	Sum/=k;
	sort(b+1,b+1+len);
	ll x;
	int id_i,id_j;
	int mask,now;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n[i];j++){
			memset(vis,0,sizeof vis);
			mask=0;
			tmp.clear();
			id_i=i,id_j=j;
			while(1){
				if(id_i==-1||vis[id_i]){
					break;
				}
				tmp.push_back(make_pair(id_i,id_j));
				vis[id_i]=1;
				mask|=(1<<(id_i-1));
				x=Sum+a[id_i][id_j]-sum[id_i];
				now=find(x);
				id_i=b[now].i;
				id_j=b[now].j;
			}
			if(id_i!=-1&&id_i==i&&id_j==j){
				f[mask]=1;
				d[mask]=tmp;
			}
		}
	}
	for(int i=1;i<(1<<k);i++){
		if(f[i]){
			g[i]=i;
			continue;
		}
		for(int j=(i-1)&i;j;j=(j-1)&i){
			if(f[j]&&g[i^j]){
				g[i]=j;
				break;
			}
		}
	}
	if(g[(1<<k)-1]){
		for(int i=(1<<k)-1;i;i^=g[i]){
			for(int j=1;j<(int)d[g[i]].size();j++){
				ans[d[g[i]][j].first][0]=a[d[g[i]][j].first][d[g[i]][j].second];
				ans[d[g[i]][j].first][1]=d[g[i]][j-1].first;
			}
			ans[d[g[i]][0].first][0]=a[d[g[i]][0].first][d[g[i]][0].second];
			ans[d[g[i]][0].first][1]=d[g[i]].back().first;
		}
		puts("Yes");
		for(int i=1;i<=k;i++){
			printf("%d %d\n",ans[i][0],ans[i][1]);
		}
	}
	else{
		puts("No");
	}
	return 0;
}