#include<bits/stdc++.h>
using namespace std;
#define MN 200005
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
	w[0].fa=-1;
	cnt=1;
	lst=0;
}
void Extend(int x){
	int cur=cnt++;
	w[cur].len=w[lst].len+1;
	Ins(root[cur],1,n,w[cur].len);
//	cerr<<"ADD: "<<w[cur].len<<" "<<root[cur]<<endl;
	int p=lst;
	while(p!=-1&&!w[p].nex[x]){
		w[p].nex[x]=cur;
		p=w[p].fa;
	}
	if(p==-1)w[cur].fa=0;
	else{
		int q=w[p].nex[x];
		if(w[q].len==w[p].len+1){
			w[cur].fa=q;
		}
		else{
			int clone=cnt++;
			w[clone].len=w[p].len+1;
			w[clone].fa=w[q].fa;
			for(int i=0;i<26;++i)w[clone].nex[i]=w[q].nex[i];
			while(p!=-1&&w[p].nex[x]==q){
				w[p].nex[x]=clone;
				p=w[p].fa;
			}
			w[q].fa=w[cur].fa=clone;
		}
	}
	lst=cur;
}
#define pii pair<int,int>
#define mp make_pair
#define fir first
#define sec second
void work(char *ch,int l,int r){
	int len=strlen(ch+1)+1;
	int pos=0,now;
	pii suf=mp(0,-1);
	ch[len]='a'-1;
	for(now=1;now<=len;++now){
		int p=0;
		for(int j=ch[now]-'a'+1;j<26;++j){
			int nxt=w[pos].nex[j];
			if(nxt&&ask(root[nxt],1,n,l+now-1,r)) {p=nxt;suf=mp(now,j);break;}
		}
		if(now==len)break;
		int nxt=w[pos].nex[ch[now]-'a'];
//		cerr<<"? "<<nxt<<" "<<root[nxt]<<endl;
		if(!nxt||!ask(root[nxt],1,n,l+now-1,r))break;
		pos=nxt;
	}
	if(suf.sec==-1){puts("-1");return;}
	for(int i=1;i<suf.fir;++i)putchar(ch[i]);
	putchar(suf.sec+'a');
	puts("");
}
int q;
char t[MN];
vector<int>edge[MN];
void MERGE(int x){
	for(int i=0;i<edge[x].size();++i){
		MERGE(edge[x][i]);
		root[x]=Merge(root[x],root[edge[x][i]],1,n);
//		cerr<<"Merge: "<<x<<" "<<root[x]<<" "<<Tree[root[x]].sum<<endl;
	}
}
int main(){
	scanf("%s",ch+1);
	n=strlen(ch+1);
	init();
	for(int i=1;i<=n;++i)Extend(ch[i]-'a');
	for(int i=1;i<cnt;++i)edge[w[i].fa].push_back(i);
	MERGE(0);
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d%s",&l,&r,t+1);
		work(t,l,r);
	}
	return 0;
}