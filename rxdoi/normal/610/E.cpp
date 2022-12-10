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

int cl[N*4],cr[N*4],cov[N*4],A[N*4][10][10];
int Ql,Qr;
int n,m,k,res;
char s[N];

void Update(int x){
	cl[x]=cl[Lsn];
	cr[x]=cr[Rsn];
	For(i,0,10) For(j,0,10){
		A[x][i][j]=A[Lsn][i][j]+A[Rsn][i][j];
	}
	A[x][cr[Lsn]][cl[Rsn]]++;
}
void Build(int x,int L,int R){
	cov[x]=-1;
	if (L==R){
		cl[x]=cr[x]=s[L]-'a';
		return;
	}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	Update(x);
}
void Cover(int x,int L,int R,int c){
	memset(A[x],0,sizeof(A[x]));
	A[x][c][c]=R-L;
	cl[x]=c;cr[x]=c;
	cov[x]=c;
}
void Down(int x,int L,int R){
	if (~cov[x]){
		Cover(Lsn,L,Mid,cov[x]);
		Cover(Rsn,Mid+1,R,cov[x]);
		cov[x]=-1;
	}
}
void Modify(int x,int L,int R){
	if (Ql<=L&&R<=Qr){
		Cover(x,L,R,s[0]-'a');
		return;
	}
	Down(x,L,R);
	if (Ql<=Mid) Modify(Lsn,L,Mid);
	if (Qr>Mid) Modify(Rsn,Mid+1,R);
	Update(x);
}

int main(){
	n=IN(),m=IN(),k=IN();
	scanf("%s",s+1);
	Build(1,1,n);
	while (m--){
		if (IN()==1){
			Ql=IN(),Qr=IN();
			scanf("%s",s);
			Modify(1,1,n);
		} else{
			res=0;
			scanf("%s",s);
			For(i,0,k) For(j,i+1,k){
				res+=A[1][s[i]-'a'][s[j]-'a'];
			}
			printf("%d\n",n-res);
		}
	}
}