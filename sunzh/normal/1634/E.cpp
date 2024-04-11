#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
map<int,PII>Map;
vector<int>a[200010];
int m;
vector<PII>pp[200010];
int len[100010];
vector<int>ans[200010];
set<int>st[200010];
int get(int x,int y){
	if(!st[x].size()) return 0;
	return *st[x].begin();
}
void qinding(int x,int y,int k,bool f=0){
	if(ans[x][y]!=-1){
		return ;
	}
	ans[x][y]=k;st[x].erase(y);
	PII to=pp[x][y];
	qinding(to.fi,to.se,k^1,f);
	if(to.fi!=x||f){
		int pos=get(x,y);
		if(pos) qinding(x,pos,k^1,1);
	}
}
int main(){
	m=read();
	for(int i=1;i<=m;++i){
		len[i]=read();
		ans[i].assign(len[i]+5,-1);
		a[i].assign(len[i]+5,0);
		pp[i].assign(len[i]+5,mp(0,0));
		for(int j=1;j<=len[i];++j){
			int x=read();a[i][j]=x;
			st[i].insert(j);
			PII t=Map[x];
			if(t.fi){
				pp[i][j]=t;pp[t.fi][t.se]=mp(i,j);
				Map[x]=mp(0,0);
			}
			else Map[x]=mp(i,j);
		}
	}
	for(auto i:Map){
		if(i.se.fi||i.se.se){
			printf("NO\n");return 0;
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=len[i];++j){
			qinding(i,j,0);
		}
	}
	printf("YES\n");
	for(int i=1;i<=m;++i){
		for(int j=1;j<=len[i];++j){
			printf("%c",ans[i][j]?'R':'L');
		}
		printf("\n");
	}
}