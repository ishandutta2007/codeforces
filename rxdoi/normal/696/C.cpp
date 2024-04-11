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

const int N=100000+19;
const int p=1e9+7,I2=(p+1)/2;

int Pow(int a,ll b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

ll A[N];
int n,x,y,tmp;
int even,one=1;

int main(){
	n=IN();
	For(i,1,n+1){
		A[i]=IN();
		if (A[i]%2==0) even=1;
		if (A[i]!=1) one=0;
	}
	if (one){
		puts("0/1");
		return 0;
	}
	tmp=2;
	For(i,1,n+1) tmp=Pow(tmp,A[i]);
	y=1ll*tmp*I2%p;
	if (even){
		x=1ll*(tmp-1+p)*Pow(3,p-2)%p;
		x=(x-2ll*(1ll*tmp*I2%p*I2%p-1+p)*Pow(3,p-2)%p+p)%p;
	} else{
		x=1ll*(1ll*tmp*I2%p-1+p)*Pow(3,p-2)%p;
	}
	printf("%d/%d\n",x,y);
}