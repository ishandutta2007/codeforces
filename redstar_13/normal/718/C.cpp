#include <bits/stdc++.h>

#define x first
#define y second
#define mod 1000000007
#define MM 400010
#define NN 100010
#define ls (u<<1)
#define rs (ls|1)
#define mid (L+R>>1)
#define C 2

using namespace std;
template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}
typedef long long INT;

int In[C][C];
int b[C][C];
int tp[C][C];
int B[C][C];
int a[NN];
pair<int,int> val[MM];
int flag[MM][C][C];
int tmp;

inline void multi(int a[C][C],int b[C][C],int c[C][C]){
	for(int i=0;i<C;i++){
		for(int j=0;j<C;j++){
			tp[i][j]=0;
			for(int k=0;k<C;k++) tp[i][j]=(tp[i][j]+(INT)a[i][k]*b[k][j])%mod;
		}
	}
	for(int i=0;i<C;i++){
		for(int j=0;j<C;j++) c[i][j]=tp[i][j];
	}
}

inline void calc(INT x){
	for(int i=0;i<C;i++){
		for(int j=0;j<C;j++){
			if(i==j) b[i][j]=1;
			else b[i][j]=0;
			if(i&&j) In[i][j]=0;
			else In[i][j]=1;
		}
	}
	while(x){
		if(x&1) multi(b,In,b);
		multi(In,In,In);
		x/=2;
	}
}

inline void push_up(int u){
	val[u].x=val[ls].x+val[rs].x;
	if(val[u].x>=mod) val[u].x-=mod;
	val[u].y=val[ls].y+val[rs].y;
	if(val[u].y>=mod) val[u].y-=mod;
}

inline void build(int u,int L,int R){
	for(int i=0;i<C;i++){
		for(int j=0;j<C;j++){
			if(i==j) flag[u][i][j]=1;
			else flag[u][i][j]=0;
		}
	}
	if(L+1==R){
		calc(a[L]);
		val[u].x=b[0][0];
		val[u].y=b[1][0];
		return;
	}
	build(ls,L,mid);
	build(rs,mid,R);
	push_up(u);
}

inline void push_down(int u){
	tmp=((INT)flag[u][0][0]*val[ls].x+(INT)flag[u][0][1]*val[ls].y)%mod;
	val[ls].y=((INT)flag[u][1][0]*val[ls].x+(INT)flag[u][1][1]*val[ls].y)%mod;
	val[ls].x=tmp;
	tmp=((INT)flag[u][0][0]*val[rs].x+(INT)flag[u][0][1]*val[rs].y)%mod;
	val[rs].y=((INT)flag[u][1][0]*val[rs].x+(INT)flag[u][1][1]*val[rs].y)%mod;
	val[rs].x=tmp;
	multi(flag[ls],flag[u],flag[ls]);
	multi(flag[rs],flag[u],flag[rs]);
	for(int i=0;i<C;i++){
		for(int j=0;j<C;j++){
			if(i==j) flag[u][i][j]=1;
			else flag[u][i][j]=0;
		}
	}
}

inline void update(int u,int L,int R,int st,int ed,int x){
	if(st>=R||ed<=L) return;
	if(st<=L&&ed>=R){
		multi(flag[u],B,flag[u]);
		tmp=((INT)B[0][0]*val[u].x+(INT)B[0][1]*val[u].y)%mod;
		val[u].y=((INT)B[1][0]*val[u].x+(INT)B[1][1]*val[u].y)%mod;
		val[u].x=tmp;
		return;
	}
	push_down(u);
	update(ls,L,mid,st,ed,x);
	update(rs,mid,R,st,ed,x);
	push_up(u);
}

inline int calc(int u,int L,int R,int st,int ed){
	if(st>=R||ed<=L) return 0;
	if(st<=L&&ed>=R) return val[u].y;
	push_down(u);
	int Ans=calc(ls,L,mid,st,ed)+calc(rs,mid,R,st,ed);
	if(Ans>=mod) Ans-=mod;
	return Ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n,m;
	gn(n,m);
	for(int i=1;i<=n;i++) gn(a[i]);
	build(1,1,n+1);
	for(int i=1;i<=m;i++){
		int ok;
		scanf("%d",&ok);
		if(ok==1){
			int st,ed,x;
			gn(st,ed);
			gn(x);
			calc(x);
			for(int ii=0;ii<C;ii++){
				for(int jj=0;jj<C;jj++) B[ii][jj]=b[ii][jj];
			}
			update(1,1,n+1,st,ed+1,x);
		}
		else{
			int st,ed;
			gn(st,ed);
			printf("%d\n",calc(1,1,n+1,st,ed+1));
		}
	}
    return 0;
}