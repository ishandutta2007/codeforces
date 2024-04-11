#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

#define x first

#define y second



using namespace std;



#define ls (u<<1)

#define rs (ls|1)

#define mid (L+R>>1)

typedef pair<int,int> pii;

typedef pair<int,pii> pi3;



#define NN 100010

#define MM 400010

int a[NN];

pi3 ansn[MM],ansx[MM];

pi3 Ln[MM],Lx[MM];

pi3 Rn[MM],Rx[MM];

int sum[MM];

bool flag[MM];



void push_up(int u){

	sum[u]=sum[ls]+sum[rs];

	ansn[u]=min(min(ansn[ls],ansn[rs]),pi3(Rn[ls].x+Ln[rs].x,pii(Rn[ls].y.x,Ln[rs].y.y)));

	ansx[u]=max(max(ansx[ls],ansx[rs]),pi3(Rx[ls].x+Lx[rs].x,pii(Rx[ls].y.x,Lx[rs].y.y)));

	Ln[u]=min(Ln[ls],pi3(Ln[rs].x+sum[ls],pii(Ln[rs].y.x,Ln[rs].y.y)));

	Lx[u]=max(Lx[ls],pi3(Lx[rs].x+sum[ls],pii(Lx[rs].y.x,Lx[rs].y.y)));

	Rn[u]=min(Rn[rs],pi3(Rn[ls].x+sum[rs],pii(Rn[ls].y.x,Rn[ls].y.y)));	

	Rx[u]=max(Rx[rs],pi3(Rx[ls].x+sum[rs],pii(Rx[ls].y.x,Rx[ls].y.y)));

}



void build(int u,int L,int R){

	if(L+1==R){

		sum[u]=a[L];

		Ln[u]=pi3(a[L],pii(0,L));

		Rn[u]=pi3(a[L],pii(L,0));

		ansn[u]=pi3(a[L],pii(L,L));

		Lx[u]=pi3(a[L],pii(0,L));

		Rx[u]=pi3(a[L],pii(L,0));

		ansx[u]=pi3(a[L],pii(L,L));

		return;

	}

	build(ls,L,mid);

	build(rs,mid,R);

	push_up(u);

}



void push_down(int u){

	if(!flag[u]) return;

	flag[ls]^=flag[u];

	flag[rs]^=flag[u];

	sum[ls]*=-1;

	swap(ansn[ls],ansx[ls]);

	swap(Ln[ls],Lx[ls]);

	swap(Rn[ls],Rx[ls]);

	sum[rs]*=-1;

	swap(ansn[rs],ansx[rs]);

	swap(Ln[rs],Lx[rs]);

	swap(Rn[rs],Rx[rs]);

	ansn[ls].x*=-1;

	ansx[ls].x*=-1;

	Ln[ls].x*=-1;

	Lx[ls].x*=-1;

	Rn[ls].x*=-1;

	Rx[ls].x*=-1;

	

	ansn[rs].x*=-1;

	ansx[rs].x*=-1;

	Ln[rs].x*=-1;

	Lx[rs].x*=-1;

	Rn[rs].x*=-1;

	Rx[rs].x*=-1;

	

	flag[u]=0;

}



void update(int u,int L,int R,int ps,int x){

	if(ps<L||ps>=R) return;

	if(L+1==R){

		sum[u]=x;

		Ln[u]=pi3(x,pii(0,L));

		Rn[u]=pi3(x,pii(L,0));

		ansn[u]=pi3(x,pii(L,L));

		Lx[u]=pi3(x,pii(0,L));

		Rx[u]=pi3(x,pii(L,0));

		ansx[u]=pi3(x,pii(L,L));

		return;

	}

	push_down(u);

	update(ls,L,mid,ps,x);

	update(rs,mid,R,ps,x);

	push_up(u);

}



void flip(int u,int L,int R,int st,int ed){

	if(ed<=L||st>=R) return;

	if(st<=L&&ed>=R){

		flag[u]^=1;

		sum[u]*=-1;

		swap(ansn[u],ansx[u]);

		swap(Ln[u],Lx[u]);

		swap(Rn[u],Rx[u]);

		ansn[u].x*=-1;

		ansx[u].x*=-1;

		Ln[u].x*=-1;

		Lx[u].x*=-1;

		Rn[u].x*=-1;

		Rx[u].x*=-1;

		return;

	}

	push_down(u);

	flip(ls,L,mid,st,ed);

	flip(rs,mid,R,st,ed);

	push_up(u);

}

pi3 resed,res;

//int Fl;

void calc(int u,int L,int R,int st,int ed){

	if(ed<=L||st>=R) return;

	if(st<=L&&ed>=R){

//		if(Fl) printf("%d %d?\n",L,R);

		res=max(res,ansx[u]);

		res=max(res,pi3(Lx[u].x+resed.x,pii(resed.y.x,Lx[u].y.y)));

//		if(Fl) printf("%d %d %d\n",ansx[u].x,ansx[u].y.x,ansx[u].y.y);

		resed=max(Rx[u],pi3(sum[u]+resed.x,pii(resed.y.x,resed.y.y)));

		return;

	}

	push_down(u);

	calc(ls,L,mid,st,ed);

	calc(rs,mid,R,st,ed);

}

pii pi[25];



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

	while(m--){

		int ok;

		scanf("%d",&ok);

		if(!ok){

			int id,val;

			scanf("%d%d",&id,&val);

			update(1,1,n+1,id,val);

		}

		else{

			int st,ed,k;

			scanf("%d%d%d",&st,&ed,&k);

			int Ans=0,End=k;

			for(int i=1;i<=k;i++){

//				if(i==2) Fl=1;

				res=pi3(-inf,pii(0,0));

				resed=pi3(-inf,pii(0,0));

				calc(1,1,n+1,st,ed+1);

				if(res.x<0){

					End=i-1;

					break;

				}

				Ans+=res.x;

//				printf("%d\n",res.x);

				flip(1,1,n+1,res.y.x,res.y.y+1);

				pi[i]=pii(res.y.x,res.y.y+1);

			}

			for(int i=1;i<=End;i++) flip(1,1,n+1,pi[i].x,pi[i].y);

			printf("%d\n",Ans);

		}

	}

    return 0;

}