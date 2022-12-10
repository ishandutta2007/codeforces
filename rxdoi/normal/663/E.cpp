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

const int p=1e9+7;
const int I2=(p+1)/2;
const int N=20;

int A[1<<N],B[1<<N];
int n,m,res=(1<<30)-1;
char s[N][100000+19];

void FWT(int *A,int n,int f){
	for (int i=1;i<n;i<<=1)
		for (int j=0;j<n;j+=i<<1)
			for (int k=j,x,y;k<j+i;k++){
				x=A[k],y=A[k+i];
				if (!f){
					A[k]=(x+y)%p;
					A[k+i]=(x-y+p)%p;
				} else{
					A[k]=1ll*(x+y)*I2%p;
					A[k+i]=1ll*(x-y+p)*I2%p;
				}
			}
}

int main(){
	n=IN(),m=IN();
	For(i,0,n) scanf("%s",s[i]);
	For(i,0,m){
		int tmp=0;
		For(j,0,n) tmp=(tmp*2+s[j][i]-'0');
		A[tmp]++;
	}
	For(t,0,1<<n){
		B[t]=min(__builtin_popcount(t),n-__builtin_popcount(t));
	}
	FWT(A,1<<n,0);
	FWT(B,1<<n,0);
	For(i,0,1<<n) A[i]=1ll*A[i]*B[i]%p;
	FWT(A,1<<n,1);
	For(i,0,1<<n) res=min(res,A[i]);
	printf("%d\n",res);
}