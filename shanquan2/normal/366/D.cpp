#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n,m;
vector<int> v[1000],left[1000],right[1000];
int dis[1000],num[6001];
queue<int> q;
bool inq[1000];
void spfa(int s,int num){
	memset(dis,-1,sizeof(dis));
	dis[s]=1000100;
	q.push(s);inq[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		int w=dis[u];
		for(int i=0;i<v[u].size();i++)if(left[u][i]<=num && right[u][i]>=num){
			int now=min(w,right[u][i]);
			if(now>dis[v[u][i]]){
				dis[v[u][i]]=now;
				if(!inq[v[u][i]])
					q.push(v[u][i]),
					inq[v[u][i]]=1;
			}
		}
		inq[u]=0;
	}
	return;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int x,y,l,r;
		scanf("%d%d%d%d",&x,&y,&l,&r);
		x--,y--;
		v[x].push_back(y);
		left[x].push_back(l);
		right[x].push_back(r);
		v[y].push_back(x);
		left[y].push_back(l);
		right[y].push_back(r);
		num[i*2]=l;num[i*2+1]=r;
	}
	sort(num,num+m*2);
	int top=unique(num,num+m*2)-num;
//	for(int i=0;i<top;i++)printf("%d\n",num[i]);
	int ans=0;
	for(int i=0;i<top;i++){
		spfa(0,num[i]);
		if(dis[n-1]-num[i]+1>ans)ans=dis[n-1]-num[i]+1;
	}
	if(ans==0)printf("Nice work, Dima!\n");else printf("%d\n",ans);
	return 0;
}