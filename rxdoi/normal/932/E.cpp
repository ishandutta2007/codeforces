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
#define lf else if 

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;
typedef vector<string> Vs;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=5000+19;
const int p=1e9+7;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

int S[N][N];
int n,k,res,tmp;

int main(){
	n=IN(),k=IN();
	For(i,0,N){
		S[i][0]=(i==0);
		For(j,1,i+1) S[i][j]=(S[i-1][j-1]+1ll*j*S[i-1][j])%p;
	}
	tmp=1;
	For(i,0,k+1) if (i<=n){
		res=(res+1ll*S[k][i]*tmp%p*Pow(2,n-i))%p;
		tmp=1ll*tmp*(n-i)%p;
	}
	printf("%d\n",res);
}