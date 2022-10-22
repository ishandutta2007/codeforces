#include<bits/stdc++.h>
using namespace std;
#define MN 1500005
#define mn 100005
struct SAM{
	int len,fa;
	map<int,int>nex;
}w[MN<<2];
char ch[MN],T[MN];
int cnt,lst,len[mn],siz[MN<<2],st[MN];
int n,q;
bool vis[MN<<2];
vector<int>loc[mn],edge[MN<<2];
void init(){
	w[0].fa=-1;
	cnt=1;
	lst=0;
}
void Ins(int a,int id,int op){
	int cur=cnt++;
	//cerr<<"INS: "<<a<<endl;
	w[cur].len=w[lst].len+1;
	int p=lst;
	if(!id)siz[cur]=1;
	if(id&&op) loc[id].push_back(cur);
	while(p!=-1&&!w[p].nex[a]){
	//	cerr<<"???? "<<p<<" "<<w[p].fa<<endl;
		w[p].nex[a]=cur;
		p=w[p].fa;
	}
	if(p==-1)w[cur].fa=0;
	else{
		int q=w[p].nex[a];
		if(w[q].len==w[p].len+1)w[cur].fa=q;
		else{
			int clone=cnt++;
			w[clone].len=w[p].len+1;
			w[clone].fa=w[q].fa;
			w[clone].nex=w[q].nex;
			while(p!=-1&&w[p].nex[a]==q){
				w[p].nex[a]=clone;
				p=w[p].fa;
			}
			w[q].fa=w[cur].fa=clone;
		}
	}
	lst=cur;
}
void dfs(int x){
	for(int i=0;i<edge[x].size();++i){
		dfs(edge[x][i]);
		siz[x]+=siz[edge[x][i]];
	}
}
int jump(int x,int len){
	while(x!=-1&&w[w[x].fa].len>=len)x=w[x].fa;
	return x;
}
int main(){
	init();
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for(int i=1;i<=n;++i)Ins(ch[i]-'a',0,0);
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		scanf("%s",T+1);
		lst=0;
		len[i]=strlen(T+1);
		for(int j=1;j<len[i];++j)Ins(T[j]-'a',i,0);
		Ins(T[len[i]]-'a',i,1);
		for(int j=1;j<len[i];++j)Ins(T[j]-'a',i,1);
	}
	for(int i=1;i<cnt;++i)edge[w[i].fa].push_back(i);
	dfs(0);
	for(int i=1;i<=q;++i){
		int N=1,ans=0;
		for(int j=0;j<loc[i].size();++j){
			int p=jump(loc[i][j],len[i]);
			if(vis[p])continue;
			ans+=siz[p];st[N++]=p;vis[p]=1;
		}
		printf("%d\n",ans);
		while(N--)vis[st[N]]=0;
	}
	return 0;
}