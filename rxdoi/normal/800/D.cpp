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

#define dprintf(...) fprintf(stderr,__V_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=1000000+19;
const int Top=1000000;
const int p=1e9+7;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

struct node{
	int c,s0,s1,s2;
} A[N];
int pw10[10],val[N];
int n,x;
ll res;

node operator + (node A,node B){
	return (node){A.c+B.c,(A.s0+B.s0)%p,(A.s1+B.s1+1ll*A.s2*B.s2)%p,(A.s2+B.s2)%p};
}

int main(){
	pw10[0]=1;
	For(i,1,10) pw10[i]=10ll*pw10[i-1]%p;
	n=IN();
	For(i,0,n){
		x=IN();
		A[x]=A[x]+(node){1,1ll*x*x%p,0,x};
	}
	For(i,0,6){
		for (int x=Top-1;~x;x--)
			if (x/pw10[i]%10!=9){
				A[x]=A[x]+A[x+pw10[i]];
			}
	}
	For(i,0,Top)
		if (A[i].c){
			val[i]=1ll*(A[i].s0+A[i].s1)*Pow(2,A[i].c-1)%p;
		}
	For(i,0,6){
		For(x,0,Top)
			if (x/pw10[i]%10!=9){
				val[x]=(val[x]-val[x+pw10[i]]+p)%p;
			}
	}
	For(i,0,Top){
		res^=1ll*i*val[i];
	}
	cout<<res<<endl;
}