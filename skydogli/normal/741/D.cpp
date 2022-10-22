#include<bits/stdc++.h>
using namespace std;
#define INF 5e8
#define MN 500005
int st[MN],siz[MN],tax[1<<23|1],col[MN];
int fa[MN],n,w[MN],ans[MN],Max,dep[MN];
vector<int>edge[MN];
inline void chkmax(int &a,int b){if(a<b)a=b;} 
void dfs1(int x){
	siz[x]=1;
//	cerr<<x<<": "<<st[x]<<endl;
	for(int i=0;i<edge[x].size();++i)
		if(fa[x]!=edge[x][i]){
			st[edge[x][i]]=st[x]^(1<<col[edge[x][i]]);
			dep[edge[x][i]]=dep[x]+1;
			dfs1(edge[x][i]);
			siz[x]+=siz[edge[x][i]];
			if(siz[edge[x][i]]>siz[w[x]])w[x]=edge[x][i];
		}
}
void chk(int x,int subrt){
//		cerr<<"? "<<x<<" "<<(st[x])<<endl;
	for(int i=0;i<22;++i){
		int ST=(1<<i);
		chkmax(Max,tax[ST^st[x]]+dep[x]-dep[subrt]*2);
//	if(x==6)cerr<<"MAX: "<<i<<" "<<Max<<" "<<(ST^st[x])<<endl;
	}
		chkmax(Max,tax[st[x]]+dep[x]-dep[subrt]*2);
}
void getans(int x,int subrt){
	chk(x,subrt);
	for(int i=0;i<edge[x].size();++i)
		if(edge[x][i]!=fa[x])getans(edge[x][i],subrt);
}
void INS(int x){
//	cerr<<"INS: "<<x<<" "<<st[x]<<endl;
	chkmax(tax[st[x]],dep[x]);
}
void cover(int x,int op){
	if(!op) tax[st[x]]=-1e9;
	else INS(x);
	for(int i=0;i<edge[x].size();++i)
		if(edge[x][i]!=fa[x])cover(edge[x][i],op);
}
void dfs2(int x,int op){
//	cerr<<"dfs: "<<x<<" "<<op<<" w[x]:"<<w[x]<<endl;
	for(int i=0;i<edge[x].size();++i)
		if(edge[x][i]!=fa[x]&&w[x]!=edge[x][i]){
			dfs2(edge[x][i],0);
			ans[x]=max(ans[x],ans[edge[x][i]]);
		}
	if(w[x]){
		dfs2(w[x],1);
		ans[x]=max(ans[x],ans[w[x]]);
	}
//	cerr<<"now: "<<x<<" "<<ans[x]<<" "<<Max<<endl;
//	cerr<<"??? "<<Max<<endl;
	chk(x,x);
	INS(x);
	for(int i=0;i<edge[x].size();++i){
		if(edge[x][i]!=fa[x]&&w[x]!=edge[x][i]){
			getans(edge[x][i],x);
			cover(edge[x][i],1);
		}
	}	
	ans[x]=max(ans[x],Max);
	if(!op){
		cover(x,0);
		Max=0;
	}
}
int main(){
	scanf("%d",&n);
	memset(tax,-0x3f,sizeof(tax));
	tax[0]=0;
	for(int i=2;i<=n;++i){
		scanf("%d",&fa[i]);
		edge[fa[i]].push_back(i);
		char c=getchar();
		while(c>'z'||c<'a')c=getchar();
		col[i]=c-'a';
	}
	dfs1(1);
	dfs2(1,1);
	for(int i=1;i<=n;++i)
		printf("%d ",ans[i]);
	return 0;
}