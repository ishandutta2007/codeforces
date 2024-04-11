#include <bits/stdc++.h>
#define ls (u<<1)
#define rs (ls|1)
#define mid (L+R>>1)
#define NN 300010
#define MM 1200010

using namespace std;
typedef long long INT;

int a[NN];
INT flag[MM];
INT lv[MM],rv[MM];
int Lv[MM][3],Rv[MM][3];
int ans[MM];

void push_up(int u,int L,int R){
	ans[u]=max(ans[ls],ans[rs]);
	if(rv[ls]>lv[rs]) ans[u]=max(ans[u],Rv[ls][2]+Lv[rs][0]);
	if(rv[ls]<lv[rs]) ans[u]=max(ans[u],Rv[ls][1]+Lv[rs][2]);
	
	
	lv[u]=lv[ls];
	
	Lv[u][0]=Lv[ls][0];
	if(Lv[ls][0]==mid-L&&rv[ls]>lv[rs]) Lv[u][0]+=Lv[rs][0];
	
	Lv[u][1]=Lv[ls][1];
	if(Lv[ls][1]==mid-L&&rv[ls]<lv[rs]) Lv[u][1]+=Lv[rs][1];
	
	Lv[u][2]=Lv[ls][2];
	if(rv[ls]>lv[rs]&&Lv[ls][2]==mid-L) Lv[u][2]+=Lv[rs][0];
	if(rv[ls]<lv[rs]&&Lv[ls][1]==mid-L) Lv[u][2]=max(Lv[u][2],mid-L+Lv[rs][2]);
	////////////////////////////////////////////////////////
	rv[u]=rv[rs];
	
	Rv[u][0]=Rv[rs][0];
	if(Rv[rs][0]==R-mid&&rv[ls]>lv[rs]) Rv[u][0]+=Rv[ls][0];
	
	Rv[u][1]=Rv[rs][1];
	if(Rv[rs][1]==R-mid&&rv[ls]<lv[rs]) Rv[u][1]+=Rv[ls][1];
	
	Rv[u][2]=Rv[rs][2];
	if(rv[ls]<lv[rs]&&Rv[rs][2]==R-mid) Rv[u][2]+=Rv[ls][1];
	if(rv[ls]>lv[rs]&&Rv[rs][0]==R-mid) Rv[u][2]=max(Rv[u][2],R-mid+Rv[ls][2]);
}

void build(int u,int L,int R){
	if(L+1==R){
		ans[u]=1;
		lv[u]=a[L];
		rv[u]=a[L];
		for(int i=0;i<3;i++){
			Lv[u][i]=1;
			Rv[u][i]=1;
		}
		return;
	}
	build(ls,L,mid);
	build(rs,mid,R);
	push_up(u,L,R);
}

void push_down(int u){
	if(!flag[u]) return;
	lv[ls]+=flag[u];
	rv[ls]+=flag[u];
	lv[rs]+=flag[u];
	rv[rs]+=flag[u];
	flag[ls]+=flag[u];
	flag[rs]+=flag[u];
	flag[u]=0;
}

void update(int u,int L,int R,int st,int ed,int x){
	if(st>=R||ed<=L) return;
	if(st<=L&&ed>=R){
		flag[u]+=x;
		lv[u]+=x;
		rv[u]+=x;
		return;
	}
	push_down(u);
	update(ls,L,mid,st,ed,x);
	update(rs,mid,R,st,ed,x);
	push_up(u,L,R);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n+1);
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int p,q,x;
		scanf("%d%d%d",&p,&q,&x);
		update(1,1,n+1,p,q+1,x);
		printf("%d\n",ans[1]);
	}
    return 0;
}