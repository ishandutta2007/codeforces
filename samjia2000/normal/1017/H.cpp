#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 1e5+5;
const int mo = 998244353;

LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}
LL quickmi(LL x,LL tim){
	LL ret=1;
	for(;tim;tim/=2,x=x*x%mo)
	if (tim&1)ret=ret*x%mo;
	return ret;
}

LL inv[N*2],js[N*2];

void prepare(){
	js[0]=js[1]=1;
	fo(i,2,2e5)js[i]=js[i-1]*i%mo;
	inv[0]=inv[1]=1;
	fo(i,2,2e5)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
}

int n,m,q;
int a[N];
struct Query{
	int l,r,k;
	int id;
}qry[N];
LL ans[N];
map<int,int>id;
int v[105];
int k;
LL val[105][N];
int blk;
int be[N];
LL nv[105];
int cnt[N];
int all[N];

bool cmp(Query a,Query b){return be[a.l]!=be[b.l]?be[a.l]<be[b.l]:a.r<b.r;}

void add(int i,int c){
	cnt[c]++;
	nv[i]=nv[i]*(v[i]+all[c]-cnt[c]+1)%mo;
}

void del(int i,int c){
	nv[i]=nv[i]*inv[v[i]+all[c]-cnt[c]+1]%mo;
	cnt[c]--;
}

void add(int c){
	cnt[c]++;
	fo(i,1,k)nv[i]=nv[i]*(v[i]+all[c]-cnt[c]+1)%mo;
}

int main(){
	prepare();
	n=get();m=get();q=get();
	fo(i,1,n){
		a[i]=get();
		all[a[i]]++;
	}
	fo(i,1,q){
		qry[i].l=get(),qry[i].r=get(),qry[i].k=get();
		qry[i].id=i;
		if (!id[qry[i].k]){
			id[qry[i].k]=++k;
			v[k]=qry[i].k;
		}
	}
	fo(i,1,k){
		LL now=v[i];
		val[i][0]=1;
		fo(x,1,n)val[i][x]=val[i][x-1]*(now*m%mo+x)%mo;
	}
	blk=sqrt(1.0*n*n*k/q)*1.2+1;
	fo(i,1,n)be[i]=(i-1)/blk+1;
	sort(qry+1,qry+1+q,cmp);
	int w=1;
	for(int L=1;L<=n;L+=blk){
		fo(i,1,m)cnt[i]=0;
		fo(i,1,k)nv[i]=1;
		while(w<=q&&be[qry[w].l]==be[L]&&be[qry[w].r]==be[L]){
			int tk=id[qry[w].k];
			LL pv=nv[tk];
			fo(i,qry[w].l,qry[w].r)add(tk,a[i]);
			ans[qry[w].id]=nv[tk]*val[tk][n-(qry[w].r-qry[w].l+1)]%mo;
			nv[tk]=pv;
			fo(i,qry[w].l,qry[w].r)cnt[a[i]]--;
			w++;
		}
		fo(R,L+blk,n){
			add(a[R]);
			while(w<=q&&be[qry[w].l]==be[L]&&qry[w].r==R){
				int tk=id[qry[w].k];
				LL pv=nv[tk];
				fd(i,L+blk-1,qry[w].l)add(tk,a[i]);
				ans[qry[w].id]=nv[tk]*val[tk][n-(qry[w].r-qry[w].l+1)]%mo;
				nv[tk]=pv;
				fo(i,qry[w].l,L+blk-1)cnt[a[i]]--;
				w++;
			}
		}
	}
	fo(i,1,q)printf("%I64d\n",ans[i]);
	return 0;
}