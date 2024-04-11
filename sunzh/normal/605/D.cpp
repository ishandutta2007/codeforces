#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<queue>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int n;
int tmpx[200010],tmpy[200010];
int cnt1,cnt2;
int dis[100010];
int a[100010],b[100010],c[100010],d[100010];
set<pair<int,int> >s[400010];
queue<int>Q;
set<pair<int,int> >::iterator it;
int stk[100010];
int pre[100010];
void insert(int x,int y,int id){
	while(x<=cnt1+1){
		s[x].insert(make_pair(y,id));
		x+=x&-x;
	}
}
void del(int x,int y,int id){
	while(x<=cnt1+1){
		s[x].erase(make_pair(y,id));
		x+=x&-x;
	}
}
void bfs(){
	for(int i=1;i<=n;++i){
		if(tmpx[a[i]]<=0&&tmpy[b[i]]<=0){
			Q.push(i);dis[i]=1;del(a[i],b[i],i);pre[i]=0;
		}
	}
	while(!Q.empty()){
		int u=Q.front();
//		printf("u:%d,dis:%d\n",u,dis[u]);
		Q.pop();
		int x=c[u];
		while(x){
			if(s[x].size()){
				int cnt=0;
				it=s[x].begin();
				while((*it).first<=d[u]&&it!=s[x].end()){
					Q.push((*it).second);dis[(*it).second]=dis[u]+1;
					pre[(*it).second]=u;
					stk[++cnt]=(*it).second;++it;
				}
				while(cnt){
					del(a[stk[cnt]],b[stk[cnt]],stk[cnt]);
					--cnt;
				}
			}
			x-=x&-x;
		}
	}
}
void dfs(int x){
	if(!x) return ;
	dfs(pre[x]);
	printf("%d ",x);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();b[i]=read();c[i]=read();d[i]=read();
		tmpx[++cnt1]=a[i];tmpx[++cnt1]=c[i];
		tmpy[++cnt2]=b[i];tmpy[++cnt2]=d[i];
	}sort(tmpx+1,tmpx+cnt1+1);sort(tmpy+1,tmpy+cnt2+1);
	cnt1=unique(tmpx+1,tmpx+cnt1+1)-tmpx-1;
	cnt2=unique(tmpy+1,tmpy+cnt2+1)-tmpy-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(tmpx+1,tmpx+cnt1+1,a[i])-tmpx;
		b[i]=lower_bound(tmpy+1,tmpy+cnt2+1,b[i])-tmpy;
		c[i]=lower_bound(tmpx+1,tmpx+cnt1+1,c[i])-tmpx;
		d[i]=lower_bound(tmpy+1,tmpy+cnt2+1,d[i])-tmpy;
	}
	for(int i=1;i<=n;++i) insert(a[i],b[i],i);
	bfs();
	if(!dis[n]) printf("-1\n");
	else printf("%d\n",dis[n]);
	if(dis[n]){
		dfs(n);
	}
	return 0;
}