#include<bits/stdc++.h>
using namespace std;
#define MN 400005
namespace seg_merge{
	int tot;
	struct tree{
		int lson,rson,sum;
	}Tree[MN*51];
#define ls(x) Tree[x].lson
#define rs(x) Tree[x].rson
#define mid ((l+r)>>1)
	int Merge(int a,int b,int l,int r){
		if(!a||!b)return a+b;
		int k=++tot;
		Tree[k].sum=Tree[a].sum+Tree[b].sum;
		Tree[k].lson=Merge(ls(a),ls(b),l,mid);
		Tree[k].rson=Merge(rs(a),rs(b),mid+1,r);
		return k;
	}
	void Ins(int &x,int l,int r,int loc){
		if(!x)x=++tot;
		Tree[x].sum++;
		if(l==r)return;
		if(loc<=mid)Ins(ls(x),l,mid,loc);
		else Ins(rs(x),mid+1,r,loc);
	}
	int ask(int x,int l,int r,int b,int e){
		//	cerr<<"ask: "<<b<<" "<<e<<endl;
		if(l>e||r<b||!x||!Tree[x].sum)return 0;
		if(b<=l&&r<=e)return Tree[x].sum;
		if(e<=mid)return ask(ls(x),l,mid,b,e);
		if(b>mid)return ask(rs(x),mid+1,r,b,e);
		return ask(ls(x),l,mid,b,e)+ask(rs(x),mid+1,r,b,e);
	}
}
using namespace seg_merge;
struct SAM{
	int len,fa;
	int nex[26];
}w[MN<<1];
int cnt,lst;
int n,root[MN<<1];
char ch[MN];
void init(){
	cnt=1;
	w[0].len=0;
	w[0].fa=-1;
	lst=0;
}
int mx[MN];
void Extend(int x){
	int cur=cnt++;
	w[cur].len=w[lst].len+1;
	Ins(root[cur],1,n,w[cur].len);
	mx[cur]=w[cur].len;
	int p=lst;
	while(p!=-1&&!w[p].nex[x]){
		w[p].nex[x]=cur;
		p=w[p].fa;
	}
	if(p==-1)w[cur].fa=0;
	else{
		//		cerr<<"PHUCC"<<endl;
		int q=w[p].nex[x];
		if(w[q].len==w[p].len+1){
			w[cur].fa=q;
		}
		else{
			//			cerr<<"?????"<<endl;
			int clone=cnt++;
			w[clone].fa=w[q].fa;
			for(int i=0;i<26;++i)w[clone].nex[i]=w[q].nex[i];
			w[clone].len=w[p].len+1;
			while(p!=-1&&w[p].nex[x]==q){
				w[p].nex[x]=clone;
				p=w[p].fa;
			}
			w[q].fa=w[cur].fa=clone;
		}
	}
	lst=cur;
}
vector<int>edge[MN];
void DFS(int x){
	for(int i=0;i<edge[x].size();++i){
		DFS(edge[x][i]);
		if(!x)continue;
		mx[x]=max(mx[x],mx[edge[x][i]]);
		root[x]=Merge(root[x],root[edge[x][i]],1,n);
	}
}
int f[MN],g[MN];
void work(int x){
//	cerr<<x<<": "<<w[x].fa<<endl;
	for(int i=0;i<edge[x].size();++i){
		int v=edge[x][i];
		if(!x){f[v]=1;g[v]=v;}
		else{
			if(ask(root[g[x]],1,n,mx[v]-w[v].len+w[g[x]].len,mx[v]-1)){
				g[v]=v;
				f[v]=f[x]+1;
				//		cerr<<"OK"<<endl;
			}
			else {g[v]=g[x];f[v]=f[x];}
		}
		work(v);
	}
}
int main(){
	scanf("%d",&n);
	scanf("%s",ch+1);
	init();
	for(int i=1;i<=n;++i)Extend(ch[i]-'a');
	//	cerr<<"CNT: "<<cnt<<endl;
	for(int i=1;i<cnt;++i)edge[w[i].fa].push_back(i);
	DFS(0);
	f[0]=1;g[0]=0;
	work(0);
	int ans=0;
	for(int i=1;i<cnt;++i)ans=max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}