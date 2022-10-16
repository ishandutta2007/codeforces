#include<bits/stdc++.h>
using namespace std;
struct edge{
	int to,next;
}e[2002];
int n,head[1002],cnt,del[1002],zx,siz[1002],mns;
void add(int x,int y){
	e[++cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
void get(int x,int y){
	siz[x]=1;
	int mxs=0;
	for(int i=head[x];i;i=e[i].next){
		if(e[i].to!=y&&!del[e[i].to]){
			get(e[i].to,x);
			siz[x]+=siz[e[i].to];
			mxs=max(mxs,siz[e[i].to]);
		}
	}
	mxs=max(mxs,n-siz[x]);
	if(mxs<mns){
		mns=mxs;
		zx=x;
	}
}
void dfs(int x,int y){
	siz[x]=1;
	for(int i=head[x];i;i=e[i].next){
		if(e[i].to!=y&&!del[e[i].to]){
			dfs(e[i].to,x);
			siz[x]+=siz[e[i].to];
		}
	}
}
void find(int x)
{
	mns=1e9;
	get(x,x);
	x=zx;
	dfs(x,x);
	if(siz[x]==1){
		printf("! %d\n",x);
		fflush(stdout);
		return;
	}
	else if(siz[x]==2){
		int y;
		for(int i=head[x];i;i=e[i].next){
			
			if(!del[e[i].to]){
				y=e[i].to;
				break;
			}
		}
		printf("? %d %d\n",x,y);
		fflush(stdout);
		cin>>x;
		printf("! %d\n",x);
		fflush(stdout);
		return;
	}
	else{
		int lst=0,lst1=0;
		for(int i=head[x];i;i=e[i].next){
			if(!del[e[i].to]){
				if(!lst)lst=e[i].to;
				else lst1=e[i].to;
			}
		}
		cout<<endl;
		printf("? %d %d\n",lst,lst1);
		fflush(stdout);
		int tmp;cin>>tmp;
		if(tmp==lst)
		{
			del[x]=1;
			n=siz[lst];
			find(lst);
		}
		else if(tmp==lst1)
		{
			del[x]=1;
			n=siz[lst1];
			find(lst1);
		}
		else
		{
			del[lst]=del[lst1]=1;
			n-=siz[lst];
			n-=siz[lst1];
			find(x);
		}
	}
}
int x,y;
int main()
{
	cin>>n;
	for(int i=1;i<n;++i)
	{
		cin>>x;
		cin>>y;
		add(x,y);
		add(y,x);
	}
	find(1);
}