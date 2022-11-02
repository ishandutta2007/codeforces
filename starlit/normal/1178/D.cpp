#include<bits/stdc++.h>
const int N=1003;
using namespace std;
map<pair<int,int>,bool>mp;
int n,p[N],t,a[N],st[N],x;
bool np[N*N];
priority_queue<pair<int,int>>q;
void dfs(int d,int v){
	if(d>n){
		if((v&1)||np[v>>1])
		return;
		printf("%d",v>>1);
		for(int i=n;i;i--)
		a[i]=p[a[i]],q.push({a[i],i});
		for(;q.size();){
			x=q.top().second;q.pop();
			assert(q.size()>=a[x]);
			for(int i=0;i<a[x];i++)
			st[i]=q.top().second,q.pop(),
			printf("\n%d %d",x,st[i]);
			for(int i=0;i<a[x];i++)
			if(--a[st[i]])q.push({a[st[i]],st[i]});
		}
		exit(0);
	}
	if(mp[{d,v}])return;
	mp[{d,v}]=1;
	for(int i=a[d-1];i<t;i++)
	a[d]=i,dfs(d+1,v+p[i]);
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	for(int j=i*i;j<=n*n;j+=i)
	np[j]=1;
	for(int i=2;i<n;i++)
	if(!np[i])p[t++]=i;
	dfs(1,0);
	puts("-1");
}