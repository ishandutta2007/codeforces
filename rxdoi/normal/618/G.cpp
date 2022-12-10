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

#define For(i,x,y) for (int i=x,_=y;i<_;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double ld;
typedef __float128 db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=50+19;
const int M=40;
const int oo=(1<<30)-1;

struct Matrix{
	db s[2*M][2*M];
} tmp,F,A;

Matrix operator * (const Matrix &A,const Matrix &B){
	memset(tmp.s,0,sizeof(tmp.s));
	For(i,0,2*M) For(k,0,2*M) For(j,0,2*M){
		tmp.s[i][j]+=A.s[i][k]*B.s[k][j];
	}
	return tmp;
}
Matrix Pow(Matrix A,int b){
	Matrix res;
	For(i,0,2*M) For(j,0,2*M) res.s[i][j]=(i==j);
	for (;b;b>>=1,A=A*A) if (b&1) res=res*A;
	return res;
}

db f[N][M],pro[N][M],pw[3][M];
db p,res,pp;
int n;

db calc(int i,int j,int b){
	if (j>i+1) return 0;
	if (j==1) return p;
	if (j==2) return b==1||i==1?1-p:1-p+p*p;
	if (j>i) b++;
	return pw[b][j];
}

int main(){
	n=IN(),p=1.0*IN()/1e9;
	For(i,0,3){
		pw[i][2]=1-p+p*p;
		For(j,3,M) pw[i][j]=pw[i][j-1]*pw[i][j-1];
		For(j,2,M) For(k,0,i) pw[i][j]*=(1-p)/(1-p+p*p);
	}
	if (n>M+5){
		F.s[0][M-1]=0;
		F.s[0][M-1+M]=1;
		For(j,1,M){
			For(k,j+1,M){
				db tmp=calc(oo,j,0);
				A.s[k+M][j+M]+=tmp;
				A.s[k][j]+=tmp;
				A.s[k+M][j]+=tmp*j;
			}
			if (j>1){
				db tmp=calc(oo,j,1);
				A.s[1+M][j+M]+=tmp;
				A.s[1][j]+=tmp;
				A.s[1+M][j]+=tmp*j;
			}
		}
		F=F*Pow(A,n-(M+5));
		n=M+5;
		For(i,0,M){
			f[0][i]=F.s[0][i];
			pro[0][i]=F.s[0][i+M];
		}
	} else{
		f[0][M-1]=0;
		pro[0][M-1]=1;
	}
	For(i,1,n+1){
		For(j,1,M){
			For(k,j+1,M){
				db tmp=calc(n-i+1,j,0);
				pro[i][j]+=pro[i-1][k]*tmp;
				f[i][j]+=f[i-1][k]*tmp;
				f[i][j]+=pro[i-1][k]*tmp*j;
			}
			if (j>1){
				db tmp=calc(n-i+1,j,1);
				pro[i][j]+=pro[i-1][1]*tmp;
				f[i][j]+=f[i-1][1]*tmp;
				f[i][j]+=pro[i-1][1]*tmp*j;
			}
		}
	}
	For(i,1,M) res+=f[n][i];
	printf("%.10lf\n",double(res));
}