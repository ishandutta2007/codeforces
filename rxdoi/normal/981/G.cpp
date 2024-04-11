#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid ((L+R)>>1)

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=2e5+19;
const int p=998244353;

int mul[N*4],plu[N*4],sum[N*4];
set<pii> S[N];
int n,q,l,r,o,Ql,Qr,Qv,opt,v;

void Mul(int x,int L,int R,int v){
	mul[x]=1ll*mul[x]*v%p;
	plu[x]=1ll*plu[x]*v%p;
	sum[x]=1ll*sum[x]*v%p;
}
void Plus(int x,int L,int R,int v){
	plu[x]=(plu[x]+v)%p;
	sum[x]=(sum[x]+1ll*v*(R-L+1))%p;
}
void Down(int x,int L,int R){
	if (mul[x]!=1){
		Mul(Lsn,L,Mid,mul[x]);
		Mul(Rsn,Mid+1,R,mul[x]);
		mul[x]=1;
	}
	if (plu[x]!=0){
		Plus(Lsn,L,Mid,plu[x]);
		Plus(Rsn,Mid+1,R,plu[x]);
		plu[x]=0;
	}
}
void Modify(int x,int L,int R){
	if (Ql<=L&&R<=Qr){
		if (o==1){
			Mul(x,L,R,Qv);
		} else{
			Plus(x,L,R,Qv);
		}
		return;
	}
	Down(x,L,R);
	if (Ql<=Mid) Modify(Lsn,L,Mid);
	if (Qr>Mid) Modify(Rsn,Mid+1,R);
	sum[x]=(sum[Lsn]+sum[Rsn])%p;
}
int Query(int x,int L,int R){
	if (Ql<=L&&R<=Qr) return sum[x];
	Down(x,L,R);
	int res=0;
	if (Ql<=Mid) res=(res+Query(Lsn,L,Mid))%p;
	if (Qr>Mid) res=(res+Query(Rsn,Mid+1,R))%p;
	return res;
}
void bao(int x){
	if (S[v].empty()) return;
	auto i=S[v].lower_bound(mp(x+1,0));
	if (i==S[v].begin()) return;
	i--;
	if (i->se>=x){
		pii T1=mp(i->fi,x-1),T2=mp(x,i->se);
		S[v].erase(i);
		if (T1.fi<=T1.se) S[v].insert(T1);
		if (T2.fi<=T2.se) S[v].insert(T2);
	}
}

int main(){
	n=IN(),q=IN();
	For(i,1,n+1) S[i].insert(mp(1,n));
	while (q--){
		opt=IN(),l=IN(),r=IN();
		if (opt==1){
			v=IN();
			o=1;
			Ql=l;
			Qr=r;
			Qv=2;
			Modify(1,1,n);
			bao(l);
			if (r+1<=n) bao(r+1);
			while (l<=r){
				auto i=S[v].lower_bound(mp(l,0));
				if (i==S[v].end()) break;
				if (i->fi>r) break;
				assert(i->fi>=l&&i->se<=r);
				o=1;
				Ql=i->fi;
				Qr=i->se;
				Qv=(p+1)/2;
				Modify(1,1,n);
				o=2;
				Qv=1;
				Modify(1,1,n);
				l=i->se+1;
				S[v].erase(*i);
			}
		} else{
			Ql=l;
			Qr=r;
			printf("%d\n",Query(1,1,n));
		}
	}
}