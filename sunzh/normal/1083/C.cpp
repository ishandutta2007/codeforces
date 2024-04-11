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
int n;
vector<int>vec[200010];
int in[200010],pos[22][400010];
int dep[200010],minn[22][400010];
int idx;
int logt[400010];
int a[200010],P[200010];
void dfs(int x,int fa){
	in[x]=++idx;pos[0][idx]=x;dep[x]=dep[fa]+1;
	for(int v:vec[x]){
		dfs(v,x);
		pos[0][++idx]=x;
	}
}
void ST(){
	for(int i=1;i<=idx;++i) minn[0][i]=dep[pos[0][i]];
	for(int i=1;i<=18;++i){
		for(int j=1;j+(1<<i)-1<=idx;++j){
			if(minn[i-1][j]>minn[i-1][j+(1<<i-1)]){
				minn[i][j]=minn[i-1][j+(1<<i-1)];
				pos[i][j]=pos[i-1][j+(1<<i-1)];
			}
			else{
				minn[i][j]=minn[i-1][j];
				pos[i][j]=pos[i-1][j];
			}
		}
	}
}
int q(int l,int r){
	if(l>r) swap(l,r);
	int k=logt[r-l+1];
	if(minn[k][l]<=minn[k][r-(1<<k)+1]) return pos[k][l];
	else return pos[k][r-(1<<k)+1];
}
int LCA(int x,int y){
	return q(in[x],in[y]);
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
struct segment{
	struct node{
		int x,y;
	}tre[800010];
	node hb(node x,int y){
		if(x.x<0||y<0) return node{-1,-1};
		int xx=x.x,xy=x.y;
		int A=dis(xx,xy);
		int B=dis(xx,y);
		int C=dis(xy,y);
		if(A+B==C) return node{xy,y};
		if(B+C==A) return x;
		if(A+C==B) return node{xx,y};
		return node{-1,-1};
	}
	node merge(node x,node y){
		if(x.x<0||y.x<0) return node{-1,-1};
		node tmp=hb(x,y.x);
		if(tmp.x<0) return node{-1,-1};
		else return hb(tmp,y.y);
	}
	void pushup(int p){
		tre[p]=merge(tre[p<<1],tre[p<<1|1]);
	}
	void build(int p,int l,int r){
		if(l==r){
			tre[p]=node{P[l],P[l]};
			return ;
		}
		int mid=l+r>>1;
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);
		pushup(p);
	}
	void change(int p,int l,int r,int pos,int k){
		if(l==r){
			tre[p]=node{k,k};return ;
		}
		int mid=l+r>>1;
		if(pos<=mid) change(p<<1,l,mid,pos,k);
		else change(p<<1|1,mid+1,r,pos,k);
		pushup(p);
	}
	int query(int p,int l,int r,node &lf){
		if(tre[p].x>0){
			if(lf.x==-1){
				lf=tre[p];return r+1;
			}
			node tmp=merge(tre[p],lf);
			if(tmp.x>0){
				lf=tmp;return r+1;
			}
		}
		if(l==r) return l;
		int mid=l+r>>1;
		int x=query(p<<1,l,mid,lf);
		if(x<=mid) return x;
		return query(p<<1|1,mid+1,r,lf);
		
	}
}T;
int main(){
	n=read();
	for(int i=2;i<=2*n;++i) logt[i]=logt[i>>1]+1;
	for(int i=1;i<=n;++i) a[i]=read()+1,P[a[i]]=i;
	for(int i=1;i<n;++i){
		int fa=read();vec[fa].pb(i+1);
	}
	dfs(1,0);
	ST();T.build(1,1,n);
	int q=read();
	while(q--){
		int op=read();
		if(op==2){
			segment::node x;x.x=-1,x.y=-1;
			printf("%d\n",T.query(1,1,n,x)-1);
			continue ;
		}
		int x=read(),y=read();
		swap(a[x],a[y]);swap(P[a[x]],P[a[y]]);
		T.change(1,1,n,a[x],x);
		T.change(1,1,n,a[y],y);
	}
}