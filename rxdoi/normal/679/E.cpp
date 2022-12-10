#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define Mid (L+R>>1)

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;
typedef pair<ll,int> pli;

const int N=100000+19;

ll bad[100];
int n,Q,o;

ll calc(ll x){
	int s=upper_bound(bad+1,bad+*bad+1,x)-bad;
	return bad[s]-x;
}
bool isbad(ll x){
	int s=lower_bound(bad+1,bad+*bad+1,x)-bad;
	return bad[s]==x;
}

struct node{
	node *L,*R;
	ll val,cov,cal,plu;
	pli Mi;
	void Cover(ll v,ll c,int l){
		val=v;
		cov=v;cal=c;plu=0;
		Mi=mp(c,l);
	}
	void Plus(ll v){
		val+=v;
		if (~cov) cov+=v,cal-=v;else plu+=v;
		Mi.fir-=v;
	}
	void Down(int l,int r){
		if (~cov){
			L->Cover(cov,cal,l);
			R->Cover(cov,cal,(l+r>>1)+1);
			cov=-1;
		}
		if (plu){
			L->Plus(plu);
			R->Plus(plu);
			plu=0;
		}
	}
	void Update(){
		Mi=min(L->Mi,R->Mi);
	}
} Nd[N*4],*cur=Nd,*rt;
int Ql,Qr,Qx;
ll Qv,Qc,val;
bool b;

bool chk;
void Build(node *&x,int L,int R){
	x=cur++;
	x->cov=-1;
	x->plu=0;
	if (L==R){
		x->val=IN();
		x->Mi=mp(calc(x->val),L);
		if (L==R) chk=(x->val==46);
		return;
	}
	Build(x->L,L,Mid);
	Build(x->R,Mid+1,R);
	x->Update();
}
void Fix(node *x,int L,int R){
	if (b||x->Mi.fir>0) return;
	if (L==R){
		b|=isbad(x->val);
		x->Mi=mp(calc(x->val),L);
		return;
	}
	if (~x->cov){
		b|=isbad(x->cov);
		x->Mi=mp(calc(x->cov),L);
		return;
	}
	x->Down(L,R);
	Fix(x->L,L,Mid);
	Fix(x->R,Mid+1,R);
	x->Update();
}
void Modify(node *x,int L,int R){
	if (Ql<=L&&R<=Qr){
		o==2?x->Cover(Qv,Qc,L):x->Plus(Qv);
		Fix(x,L,R);
		return;
	}
	x->Down(L,R);
	if (Ql<=Mid) Modify(x->L,L,Mid);
	if (Qr>Mid) Modify(x->R,Mid+1,R);
	x->Update();
}
ll Qval(node *x,int L,int R){
	if (L==R) return x->val;
	x->Down(L,R);
	return Qx<=Mid?Qval(x->L,L,Mid):Qval(x->R,Mid+1,R);
}
pli Qmin(node *x,int L,int R){
	if (Ql<=L&&R<=Qr) return x->Mi;
	x->Down(L,R);
	pli res=mp(1ll<<60,0);
	if (Ql<=Mid) res=min(res,Qmin(x->L,L,Mid));
	if (Qr>Mid) res=min(res,Qmin(x->R,Mid+1,R));
	return res;
}

int main(){
	//freopen("E.in","r",stdin);
	n=IN(),Q=IN();
	for (ll x=1;x<=1e17;x*=42) bad[++*bad]=x;
	Build(rt,1,n);
	while (Q--){
		o=IN();
		if (o==1){
			Qx=IN();
			printf("%I64d\n",Qval(rt,1,n));
		}
		if (o==2){
			Ql=IN(),Qr=IN(),Qv=IN();
			Qc=calc(Qv);
			Modify(rt,1,n);
		}
		if (o==3){
			Ql=IN(),Qr=IN(),Qv=IN();
			for (b=1;b;){
				b=0;
				Modify(rt,1,n);
			}
		}
	}
}