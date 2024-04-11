#include<cstdio>
#include<queue>
using namespace std;
int n,a[1005],ans[1000005][2],tot;
struct cmp{bool operator()(int p,int q){return a[p]>a[q];}};
priority_queue<int,vector<int>,cmp>q;
void opt(int u,int v){
	a[v]-=a[u];
	a[u]+=a[u];
	ans[tot][0]=u,ans[tot][1]=v,tot++;
}
int main(){
	scanf("%d",&n);
	int cnt=0;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		if(a[i])q.push(i);
	}
	if(q.size()<=1)return puts("-1");
	while(q.size()>2){
		int x=q.top();q.pop();
		int y=q.top();q.pop();
		int z=q.top();q.pop();
		for(int i=a[y]/a[x];i;i>>=1)
			if(i&1)opt(x,y);
			else opt(x,z);
		q.push(x);
		if(a[y])q.push(y);
		q.push(z);
	}
	printf("%d\n",tot);
	for(int i=0;i<tot;i++)printf("%d %d\n",ans[i][0]+1,ans[i][1]+1);
}