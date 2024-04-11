#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
char s[100010];
int n;
int idx;
int rt[200010];
int cnt;
int ls[2000010],rs[2000010],ml[2000010],mr[2000010];
long long sum[2000010];
long long ans;
int logt[400010];
int mn[20][400010],dep[200010];
int dfn[200010];
int merge(int x,int y,int l,int r);
struct SAM{
	int pos[100010];
	int maxlen[200010],link[200010],map[200010][26];
	int p,last,tot=1;
	void ins(int c,int id){
		int p=++tot;
		maxlen[p]=maxlen[last]+1;pos[id]=p;
		int x=last;
		while(x&&!map[x][c])map[x][c]=p,x=link[x];
		if(x){
			if(maxlen[x]+1==maxlen[map[x][c]]) link[p]=map[x][c];
			else{
				int y=map[x][c];
				int z=++tot;
				link[z]=link[y];
				for(int i=0;i<26;++i) map[z][i]=map[y][i];
				maxlen[z]=maxlen[x]+1;
				link[y]=link[p]=z;
				while(x&&map[x][c]==y) map[x][c]=z,x=link[x];
			}
		}
		else link[p]=1,map[1][c]=p;
		last=p;
	}
	vector<int>vec[200010];
	void dfs(int x){
		dfn[x]=++idx;mn[0][idx]=x;
		dep[x]=dep[link[x]]+maxlen[x]-maxlen[link[x]];
		for(int v:vec[x]){
			dfs(v);
			mn[0][++idx]=x;
		}
	}
	void build(){
		for(int i=2;i<=tot;++i) vec[link[i]].pb(i);
		dfs(1);//printf("idx:%d\n",idx);
		for(int i=1;i<=19;++i){
			for(int j=1;j+(1<<i)<=idx;++j){
				if(dep[mn[i-1][j]]<dep[mn[i-1][j+(1<<i-1)]]){
					mn[i][j]=mn[i-1][j];
				}
				else mn[i][j]=mn[i-1][j+(1<<i-1)];
			}
		}
	}
	int query(int l,int r){
		if(l==0||r==0) return 0;
		if(l>r) swap(l,r);
		int k=logt[r-l+1];
		if(dep[mn[k][l]]<dep[mn[k][r-(1<<k)+1]]) return mn[k][l];
		else return mn[k][r-(1<<k)+1];
	}
	void dfs2(int x){
		for(int v:vec[x]){
			dfs2(v);
			rt[x]=merge(rt[x],rt[v],1,idx);
		}
		ans+=1ll*sum[rt[x]]*(maxlen[x]-maxlen[link[x]]);
//		printf("%d %d %d\n",maxlen[x],maxlen[link[x]],sum[rt[x]]);
	}
	void build2(){
		for(int i=2;i<=tot;++i) vec[link[i]].pb(i);
		dfs2(1);
	}
}LR,RL;
void pushup(int p){
	sum[p]=sum[ls[p]]+sum[rs[p]]-dep[RL.query(mr[ls[p]],ml[rs[p]])];
	ml[p]=ml[ls[p]]?ml[ls[p]]:ml[rs[p]];
	mr[p]=mr[rs[p]]?mr[rs[p]]:mr[ls[p]];
}
int merge(int x,int y,int l,int r){
	if(!x||!y) return x|y;
	if(l==r) return x;
	int mid=l+r>>1;
	ls[x]=merge(ls[x],ls[y],l,mid);
	rs[x]=merge(rs[x],rs[y],mid+1,r);
	pushup(x);return x;
}
void ins(int &p,int l,int r,int pos){
	if(!p) p=++cnt;
//	printf("l:%d,r:%d,pos:%d\n",l,r,pos);
	if(l==r){
		ml[p]=mr[p]=l;sum[p]=dep[mn[0][pos]];return ;
	}
	int mid=l+r>>1;
	if(pos<=mid) ins(ls[p],l,mid,pos);
	else ins(rs[p],mid+1,r,pos);
	pushup(p);
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=2;i<=400000;++i) logt[i]=logt[i>>1]+1; 
	for(int i=1;i<=n;++i){
		LR.ins(s[i]-'a',i);
		ans+=LR.maxlen[LR.pos[i]]-LR.maxlen[LR.link[LR.pos[i]]];
		if(i==n-1) ans<<=1;
//		printf("i:%d,ans:%d,%d,%d\n",i,ans,LR.maxlen[LR.pos[i]],LR.maxlen[LR.link[LR.pos[i]]]);
	}
//	printf("%d\n",ans);
	for(int i=n;i>=1;--i){
		RL.ins(s[i]-'a',i);
		if(i>1) ans+=RL.maxlen[RL.pos[i]]-RL.maxlen[RL.link[RL.pos[i]]];
	}
//	printf("%d\n",ans);
//	printf("4328947943");
	RL.build();
	for(int i=1;i<n-1;++i){
//		printf("%d\n",RL.pos[i+2]);
		ins(rt[LR.pos[i]],1,idx,dfn[RL.pos[i+2]]);
	}
	LR.build2();
	printf("%lld\n",ans+2);
}