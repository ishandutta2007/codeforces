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
#define fi first
#define se second
#define Lsn (x<<1)
#define Rsn (x<<1|1)
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

const int N=200000+19;
const int oo=(1<<30)-1;

char s[N];
int pre7[N];
int sum2[N],sum0[N],sum1[N],sum6[N];
int n,Q,Ql,Qr,tmp,l,r,res,sum;

struct Info{
	int s[3][3];
	void Reset(){
		For(i,0,3) For(j,0,3) s[i][j]=oo;
	}
} I[N*4];

Info operator + (Info A,Info B){
	static Info C;
	For(i,0,3) For(j,0,3) C.s[i][j]=min(A.s[i][j],B.s[i][j]);
	For(i,0,3) For(j,0,3) For(k,i,j)
		if (A.s[i][k]!=oo&&B.s[k+1][j]!=oo){
			C.s[i][j]=min(C.s[i][j],A.s[i][k]+B.s[k+1][j]);
		}
	return C;
}

void Build(int x,int L,int R){
	if (L==R){
		I[x].Reset();
		if (s[L]=='2') I[x].s[0][0]=sum2[L]-sum0[L];
		if (s[L]=='0') I[x].s[1][1]=sum0[L]-sum1[L];
		if (s[L]=='1') I[x].s[2][2]=sum1[L]-sum6[L];
		return;
	}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	I[x]=I[Lsn]+I[Rsn];
}
Info Query(int x,int L,int R){
	if (Ql<=L&&R<=Qr) return I[x];
	if (Qr<=Mid) return Query(Lsn,L,Mid);
	if (Ql>Mid) return Query(Rsn,Mid+1,R);
	return Query(Lsn,L,Mid)+Query(Rsn,Mid+1,R);
}

int main(){
	n=IN(),Q=IN();
	scanf("%s",s+1);
	for (int i=1;i<=n;i++){
		pre7[i]=(s[i]=='7'?i:pre7[i-1]);
		sum2[i]=sum2[i-1]+(s[i]=='2');
		sum0[i]=sum0[i-1]+(s[i]=='0');
		sum1[i]=sum1[i-1]+(s[i]=='1');
		sum6[i]=sum6[i-1]+(s[i]=='6');
	}
	Build(1,1,n);
	while (Q--){
		res=oo;
		l=Ql=IN(),r=Qr=IN();
		Qr=pre7[Qr];
		if (Ql>Qr){
			puts("-1");
			continue;
		}
		Info res=Query(1,1,n);
		if (res.s[0][2]==oo){
			puts("-1");
			continue;
		}
		printf("%d\n",res.s[0][2]-sum2[l-1]+sum6[r]-3);
	}
}