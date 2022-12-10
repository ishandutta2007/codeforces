#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid ((L+R)>>1)

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

const int len=200000;
inline char nc(){
	static char buf[len],*b=buf+len;
	if (b==buf+len) fread(buf,1,len,stdin),b=buf;
	return *b++;
}
int IN(){
	int c,f,x;
	while (!isdigit(c=nc())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=nc())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=200000+19;

ll sum;
int cnt;
int Ql,Qr,Qv;

struct SegTree{
	ll sum[530000];
	int plu[530000],cnt[530000],val[N];
	void Update(int x,int L,int R){
		sum[x]=(plu[Lsn]?0:sum[Lsn])+(plu[Rsn]?0:sum[Rsn]);
		cnt[x]=(plu[Lsn]?0:cnt[Lsn])+(plu[Rsn]?0:cnt[Rsn]);
	}
	void Build(int x,int L,int R){
		if (L==R){
			sum[x]=val[L];
			cnt[x]=!!val[L];
			return;
		}
		Build(Lsn,L,Mid);
		Build(Rsn,Mid+1,R);
		Update(x,L,R);
	}
	void Modify(int x,int L,int R){
		if (Ql<=L&&R<=Qr){
			plu[x]+=Qv;
			return;
		}
		if (Ql<=Mid) Modify(Lsn,L,Mid);
		if (Qr>Mid) Modify(Rsn,Mid+1,R);
		Update(x,L,R);
	}
	void Query(int x,int L,int R){
		if (plu[x]) return;
		if (Ql<=L&&R<=Qr){
			::sum+=sum[x];
			::cnt+=cnt[x];
			return;
		}
		if (Ql<=Mid) Query(Lsn,L,Mid);
		if (Qr>Mid) Query(Rsn,Mid+1,R);
	}
} S[2][2];

struct node{
	int x,l,r;
	bool u,o,v;
	bool operator < (const node &B) const{
		return x<B.x||x==B.x&&v>B.v;
	}
} V[5200000];
int s[N];
int m,n,l,r,c,num;
ll res;

void Ins(int u,int L,int R,int o,int l,int r){
	if (L>R||l>r) return;
	V[num++]=(node){L,l,r,bool(u),bool(o),1};
	V[num++]=(node){R+1,l,r,bool(u),bool(o),0};
}
void work(){
	l=IN(),r=IN();
	if ((r-l+1)%2==0){
		Ins(0,1,l-1,(l+1)%2,l,n);
		Ins(1,1,l-1,(l+1)%2,l,n);
		Ins(0,1,l-1,l%2,r+1,n);
		Ins(1,1,l-1,l%2,r+1,n);
		Ins(l%2,l,r,(l+1)%2,l,n);
		Ins(l%2,l,r,l%2,r+1,n);
		Ins((l+1)%2,l,r,l%2,l,r);
	} else{
		Ins(0,1,l-1,(l+1)%2,l,r);
		Ins(1,1,l-1,(l+1)%2,l,r);
		Ins(l%2,l,r,(l+1)%2,l,r);
		Ins((l+1)%2,l,r,l%2,l,n);
		Ins((l+1)%2,l,r,(l+1)%2,r+1,n);
	}
	s[l]++;
	s[r+1]--;
}

int main(){
	m=IN(),n=IN();
	For(i,1,m+1) work();
	For(i,1,n+1) s[i]+=s[i-1];
	For(i,1,n+1) if (s[i]==0){
		int l=i,r;
		for (r=i;r+1<=n&&s[r+1]==0;r++);
		For(a,0,2) For(b,0,2) Ins(a,l,r,b,l,r);
		i=r;
	}
	sort(V,V+num);
//	sort(V.begin(),V.end());
	For(i,1,n+1){
		S[0][i&1].val[i]=i;
		S[1][i&1].val[i]=i;
	}
	For(a,0,2) For(b,0,2) S[a][b].Build(1,1,n);
	For(i,1,n+1){
		for (;c<num&&V[c].x==i;c++){
			node T=V[c];
			Ql=T.l;Qr=T.r;Qv=T.v?1:-1;
			S[T.u][T.o].Modify(1,1,n);
//			for (int j=T.l;j<=T.r;j++) tmp[T.u][T.o][j]+=T.v;
		}
		For(b,0,2){
			sum=0;cnt=0;
			Ql=i,Qr=n;
			S[i&1][b].Query(1,1,n);
			res+=sum-1ll*cnt*(i-1);
		}
		/*
		For(j,i,n+1){
			if (tmp[i&1][j&1][j]==0) res+=j-i+1,printf("(%d,%d)\n",i,j);
		}
		*/
	}
	cout<<res<<endl;
}