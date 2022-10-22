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
#define int long long
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
int n,s;
char str[11];
signed rt[200010];
const long long inf=1e15;
struct node{
	long long minn,tag;
	signed ls,rs;
}sg[8000010];
signed cnt;
int m;
int a[200010];
struct Q{
	int op,x,y;
}q[200010];
signed stk[200010];
signed ed[200010],fr[200010];
int top;
int new_node(int x=inf){
	sg[++cnt].minn=x;
	return cnt;
}
void pushup(int x){
	sg[x].minn=inf;
	int ls=sg[x].ls,rs=sg[x].rs;
	if(ls) sg[x].minn=min(sg[x].minn,sg[ls].minn);
	if(rs) sg[x].minn=min(sg[x].minn,sg[rs].minn);
}
void build(signed &x,int l,int r){
	x=new_node();
	if(l==r) return ;
	int mid=l+r>>1;
	build(sg[x].ls,l,mid);
	build(sg[x].rs,mid+1,r);
	pushup(x);
}
void pushdown(int p){
	if(sg[p].tag){
		int ls=sg[p].ls,rs=sg[p].rs;
		if(ls) sg[ls].tag+=sg[p].tag,sg[ls].minn+=sg[p].tag;
		if(rs) sg[rs].tag+=sg[p].tag,sg[rs].minn+=sg[p].tag;
		sg[p].tag=0;
	}
}
void change(int x,int l,int r,int pos,int k){
	if(l==r){
		sg[x].minn=k;
		return ;
	}
	if(!sg[x].ls) sg[x].ls=new_node();
	if(!sg[x].rs) sg[x].rs=new_node();
	pushdown(x);
	int mid=l+r>>1;
	if(pos<=mid) change(sg[x].ls,l,mid,pos,k);
	else change(sg[x].rs,mid+1,r,pos,k);
	pushup(x);
}
void update(int x,int l,int r,int L,int R,int k){
	if(L>R) return ;
	if(l>=L&&r<=R){
		sg[x].minn+=k,sg[x].tag+=k;return ;
	}
	if(!sg[x].ls) sg[x].ls=new_node();
	if(!sg[x].rs) sg[x].rs=new_node();
	pushdown(x);
	int mid=l+r>>1;
	if(L<=mid) update(sg[x].ls,l,mid,L,R,k);
	if(R>mid) update(sg[x].rs,mid+1,r,L,R,k);
	pushup(x);
}

int query(int p,int l,int r,int pos){
	if(!p) return inf;
	if(l==r) return sg[p].minn;
	if(sg[p].minn>=inf) return inf;
	pushdown(p);
	int mid=l+r>>1;
	if(pos<=mid) return query(sg[p].ls,l,mid,pos);
	else return query(sg[p].rs,mid+1,r,pos);
}

void newtree(signed &x,int l,int r,int pos,int k){
	x=new_node();
	if(l==r){
		sg[x].minn=k;return ;
	}
	int mid=l+r>>1;
	if(pos<=mid) newtree(sg[x].ls,l,mid,pos,k);
	else newtree(sg[x].rs,mid+1,r,pos,k);
	pushup(x);
}

void modify(signed &x,int ax,int bx,int l,int r){
	if(!ax||!bx){
		if(ax+bx==0){
			x=new_node();return ;
		}
		else x=ax+bx;
		return ;
	}
	x=ax;
	sg[x].minn=min(sg[ax].minn,sg[bx].minn);
	if(l==r){
		return ;
	}
	pushdown(ax),pushdown(bx);
	int mid=l+r>>1;
	modify(sg[x].ls,sg[ax].ls,sg[bx].ls,l,mid);
	modify(sg[x].rs,sg[ax].rs,sg[bx].rs,mid+1,r);
	pushup(x);
}
signed main(){
	n=read(),s=read();
	a[++m]=s;a[++m]=0;
	for(int i=1;i<=n;++i){
		scanf("%s",str+1);
		if(str[1]=='s'){
			q[i].op=1;q[i].x=read(),q[i].y=read();a[++m]=q[i].x;
		}
		else if(str[1]=='i'){
			q[i].op=2,q[i].x=read();a[++m]=q[i].x;
			stk[++top]=i;
		}
		else{
			q[i].op=3;
			fr[i]=stk[top];
			ed[stk[top]]=i;
			--top;
		}
	} 
	sort(a+1,a+m+1);
	m=unique(a+1,a+m+1)-a-1;
	build(rt[0],1,m);
	change(rt[0],1,m,1,0);
	for(int i=1;i<=n;++i){
		if(q[i].op==1){
			rt[i]=rt[i-1];
			int x=lower_bound(a+1,a+m+1,q[i].x)-a;
			int y=sg[rt[i]].minn;
			if(q[i].x!=s) change(rt[i],1,m,x,y);
			update(rt[i],1,m,1,x-1,q[i].y);
			update(rt[i],1,m,x+1,m,q[i].y);
		}
		else if(q[i].op==2){
			int x=lower_bound(a+1,a+m+1,q[i].x)-a;
			int y=query(rt[i-1],1,m,x);
			newtree(rt[i],1,m,x,y);
			change(rt[i-1],1,m,x,inf);
		}
		else{
			modify(rt[i],rt[i-1],rt[fr[i]-1],1,m);
		}
	}
	printf("%lld\n",sg[rt[n]].minn);
	return 0;
}