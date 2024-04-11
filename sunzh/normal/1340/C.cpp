#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int n,m;
int d[10010];
int g,r;
long long ans=0x7f7f7f7f7f7f7f7f;
int dis[10010][1010];
bool vis[10010][1010];
deque<pair<int,int> >q;
int main(){
	n=read(),m=read();
	for(register int i=1;i<=m;++i) d[i]=read();
	g=read(),r=read();
	for(register int i=1;i<=m;++i) for(register int j=0;j<=g;++j) dis[i][j]=-1;
	sort(d+1,d+m+1);
	q.push_back(make_pair(1,0));
	dis[1][0]=0;vis[1][0]=1;
	while(!q.empty()){
		pair<int,int> u=q.front();q.pop_front();
		if(dis[u.first][u.second]*(g+r)>=ans) continue ;
		if(u.second+n-d[u.first]<=g){
			ans=min(ans,1ll*dis[u.first][u.second]*(g+r)+u.second+n-d[u.first]);
			continue ;
		}
		if(u.first==m){
			ans=min(ans,1ll*dis[u.first][u.second]*(g+r)+u.second);
			continue ;
		}
		if(u.second==g){
			if(vis[u.first][0]==0){vis[u.first][0]=1; dis[u.first][0]=dis[u.first][u.second]+1;q.push_back(make_pair(u.first,0));}
		}
		if(u.first<m){
			if(u.second+d[u.first+1]-d[u.first]<=g) if(vis[u.first+1][u.second+d[u.first+1]-d[u.first]]==0){
				vis[u.first+1][u.second+d[u.first+1]-d[u.first]]=1;
				dis[u.first+1][u.second+d[u.first+1]-d[u.first]]=dis[u.first][u.second];
				q.push_front(make_pair(u.first+1,u.second+d[u.first+1]-d[u.first]));
			}
		}
		if(u.first>1){
			if(u.second+d[u.first]-d[u.first-1]>g) continue ;
			if(vis[u.first-1][u.second+d[u.first]-d[u.first-1]]) continue ;
			vis[u.first-1][u.second+d[u.first]-d[u.first-1]]=1;
			dis[u.first-1][u.second+d[u.first]-d[u.first-1]]=dis[u.first][u.second];
			q.push_front(make_pair(u.first-1,u.second+d[u.first]-d[u.first-1]));
		}
	}
	printf("%lld\n",ans>=0x3f3f3f3f3f3f3f3f?-1:ans);
}