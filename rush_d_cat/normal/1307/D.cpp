#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 200000 + 10;
int n,m,k,a[N];
vector<int> g[N];
int dis1[N],dis2[N];

struct Item {
	int x,y;
	bool operator<(const Item&o)const{
		return x-y<o.x-o.y;
	}
} it[N];

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		int x,y; scanf("%d%d",&x,&y);
		g[x].push_back(y); g[y].push_back(x);
	}

	{
		memset(dis1,-1,sizeof(dis1));
		queue<int> q; q.push(1); dis1[1]=0;
		while(q.size()){
			int u=q.front(); q.pop();
			for(auto v:g[u]){
				if(dis1[v]==-1){
					dis1[v]=dis1[u]+1; q.push(v);
				}
			}
		}
	}

	{
		memset(dis2,-1,sizeof(dis2));
		queue<int> q; q.push(n); dis2[n]=0;
		while(q.size()){
			int u=q.front(); q.pop();
			for(auto v:g[u]){
				if(dis2[v]==-1){
					dis2[v]=dis2[u]+1; q.push(v);
				}
			}
		}
	}
	for(int i=1;i<=k;i++){
		it[i]=(Item){dis1[a[i]],dis2[a[i]]};
	}
	sort(it+1,it+1+k);
	int xmin = 0, ans = 0;
	for(int i=1;i<=k;i++){
		if(i>=2) {
			ans=max(ans,it[i].y + xmin + 1);
		}
		xmin=max(xmin, it[i].x);
	}
	int ymin = 0;
	for(int i=k;i>=1;i--){
		if(i<k){
			ans=max(ans,it[i].x + ymin + 1);
		}
		ymin=max(ymin, it[i].y);
	}
	ans=min(ans, dis1[n]);
	cout << ans << endl;
}