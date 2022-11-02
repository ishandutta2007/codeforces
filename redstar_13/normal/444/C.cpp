#include <bits/stdc++.h>

using namespace std;

typedef long long INT;
typedef pair<INT,int> pii;
#define ls (u<<1)
#define rs (ls|1)
#define x first
#define y second
#define mid (L+R>>1)
#define NN 100010
#define MM 400010
INT ans[MM];
int mx[MM],mn[MM];
pii flag[MM];

void push_up(int u){
	mx[u]=max(mx[ls],mx[rs]);
	mn[u]=min(mn[ls],mn[rs]);
	ans[u]=ans[ls]+ans[rs];
}

void build(int u,int L,int R){
	if(L+1==R){
		mx[u]=L;
		mn[u]=L;
		return;
	}
	build(ls,L,mid);
	build(rs,mid,R);
	push_up(u);
}

void push_down(int u,int L,int R){
	if(flag[u].x){
		ans[ls]+=(INT)flag[u].x*(mid-L);
		ans[rs]+=(INT)flag[u].x*(R-mid);
		flag[ls].x+=flag[u].x;
		flag[rs].x+=flag[u].x;
		flag[ls].y=flag[u].y;
		flag[rs].y=flag[u].y;
		mx[ls]=flag[u].y;
		mn[ls]=flag[u].y;
		mx[rs]=flag[u].y;
		mn[rs]=flag[u].y;
		flag[u].x=0;
	}
}

void update(int u,int L,int R,int st,int ed,int x){
	if(st>=R||ed<=L) return;
	if(st<=L&&ed>=R){
		if(mn[u]==mx[u]){
			int y=mn[u];
			flag[u].x+=abs(y-x);
			flag[u].y=x;
			ans[u]+=(INT)(R-L)*abs(y-x);
			mx[u]=x;
			mn[u]=x;
			return;
		}
	}
	push_down(u,L,R);
	update(ls,L,mid,st,ed,x);
	update(rs,mid,R,st,ed,x);
	push_up(u);
}

INT calc(int u,int L,int R,int st,int ed){
	if(st>=R||ed<=L) return 0;
	if(st<=L&&ed>=R) return ans[u];
	push_down(u,L,R);
	return calc(ls,L,mid,st,ed)+calc(rs,mid,R,st,ed);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int n,m;
	scanf("%d%d",&n,&m);
	build(1,1,n+1);
	for(int i=1;i<=m;i++){
		int tp,st,ed;
		scanf("%d%d%d",&tp,&st,&ed);
		if(tp==1){
			int x;
			scanf("%d",&x);
			update(1,1,n+1,st,ed+1,x);
		}
		else printf("%I64d\n",calc(1,1,n+1,st,ed+1));
	}
    return 0;
}