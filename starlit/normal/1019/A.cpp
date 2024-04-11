#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define N 3003
using namespace std;
long long now,ans=1e18;
int n,m,x,y,a[N],b[N],cnt;
priority_queue<int>q[N],al,del;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		a[i]=x;
		b[i]=x>1?y:-1;
	}
	for(int i=1;i<=n;i++){
		now=0;
		for(;al.size();al.pop());
		for(;del.size();del.pop());
		for(int j=1;j<=m;j++)
		for(;q[j].size();q[j].pop());
        for(int j=1;j<=n;j++){
			if(b[j]>=0)al.push(-b[j]);
			q[a[j]].push(-b[j]);
        }
		cnt=q[1].size();
		for(int j=2;j<=m;j++)
		for(;q[j].size()>=i;){
			now-=q[j].top(),del.push(q[j].top()),q[j].pop();
			cnt++;
		}
		for(;cnt<i;){
			for(;del.size()&&al.top()
			==del.top();al.pop(),del.pop());
			if(!al.size())break;
			now-=al.top(),al.pop(),cnt++;
		}
		if(cnt==i)ans=min(ans,now);
	}
	printf("%I64d",ans);
}