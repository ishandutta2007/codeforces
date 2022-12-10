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

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

ll IN(){
	int c,f;ll x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=200+19;
const ll oo=1ll<<60;

ll L,ans;
int A[N],key[N],Fail[N],go[N][26];
int n,x,tot;
string s;

void BuildAC(){
	static int Q[N];
	int f=1,w=0;Q[1]=0;
	while (f>w){
		int x=Q[++w];
		if (x) key[x]+=key[Fail[x]];
		For(i,0,26){
			int &u=go[x][i];
			if (u){
				Q[++f]=u;
				if (x) Fail[u]=go[Fail[x]][i];
			} else{
				u=go[Fail[x]][i];
			}
		}
	}
}

struct Matrix{
	ll s[N][N];
} tmp,res,F;

Matrix operator * (const Matrix &A,const Matrix &B){
	For(i,0,tot+1) For(j,0,tot+1) tmp.s[i][j]=-oo;
	For(i,0,tot+1)
		For(j,0,tot+1){
			For(k,0,tot+1) tmp.s[i][j]=max(tmp.s[i][j],A.s[i][k]+B.s[k][j]);
		}
	return tmp;
}
Matrix Pow(Matrix A,ll b){
	res=A;
	for (--b;b;b>>=1,A=A*A) if (b&1) res=res*A;
	return res;
}

int main(){
	n=IN();L=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1){
		cin>>s;
		x=0;
		For(j,0,s.length()){
			int &u=go[x][s[j]-'a'];
			if (!u) u=++tot;x=u;
		}
		key[x]+=A[i];
	}
	BuildAC();
	For(i,0,tot+1) For(j,0,tot+1) F.s[i][j]=-oo;
	For(i,0,tot+1)
		For(j,0,26){
			int x=go[i][j];
			F.s[i][x]=key[x];
		}
	F=Pow(F,L);
	For(i,0,tot+1) ans=max(ans,F.s[0][i]);
	printf("%I64d\n",ans);
}