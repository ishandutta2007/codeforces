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

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int top=1e7,N=top+19;
const int p=1e9+7;

bool vis[N];
int pri[N/10],mu[N],A[N],B[N],C[N],Pow2[N];
int n,x,res,num;

void Init(){
	mu[1]=1;
	For(i,2,top+1){
		if (!vis[i]){
			pri[++*pri]=i;
			mu[i]=p-1;
		}
		for (int j=1;j<=*pri&&pri[j]*i<=top;j++){
			vis[pri[j]*i]=1;
			if (i%pri[j]==0){
				mu[pri[j]*i]=0;
				break;
			} else{
				mu[pri[j]*i]=p-mu[i];
			}
		}
	}
	Pow2[0]=1;
	For(i,1,top+1) Pow2[i]=2ll*Pow2[i-1]%p;
}

int main(){
	Init();
	n=IN();
	For(i,1,n+1){
		x=IN();
		A[x]++;C[x]++;
	}
	for (int i=1;i<=top;i++)
		for (int j=i+i;j<=top;j+=i) A[i]+=A[j];
	memcpy(B,A,sizeof(A));
	For(i,1,top+1) A[i]=(Pow2[A[i]]+p-1)%p;
	For(i,1,top+1) num=(num+1ll*mu[i]*A[i])%p;
	For(i,1,top+1){
		res=(res+1ll*mu[i]*A[i]%p*B[i])%p;
		res=(res-1ll*C[i]*num%p+p)%p;
	}
	printf("%d\n",res);
}