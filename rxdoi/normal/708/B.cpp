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

const int N=100000+19;

int A[N];
int a00,a01,a10,a11,n0,n1;

ll calc(int n){
	return 1ll*n*(n-1)/2;
}
void Exit(){
	puts("Impossible");
	exit(0);
}

int main(){
	a00=IN(),a01=IN(),a10=IN(),a11=IN();
	
	for (n0=1;calc(n0)<a00;n0++);
	if (calc(n0)!=a00) Exit();

	for (n1=1;calc(n1)<a11;n1++);
	if (calc(n1)!=a11) Exit();
	
	if (a01==0&&a10==0){
		if (a00&&a11) Exit();
		if (!a00&&!a11) return puts("0"),0;
		if (a00){
			For(i,0,n0) putchar('0');
		} else{
			For(i,0,n1) putchar('1');
		}
		return puts(""),0;
	}

	if (0ll+a00+a01+a10+a11!=calc(n0+n1)) Exit();
	if (a01>1ll*n0*n1) Exit();
	For(i,1,n1+1){
		A[i]=min(a01,n0);
		a01-=min(a01,n0);
	}
	for (int i=n1;i;i--){
		For(j,0,A[i]-A[i+1]) putchar('0');
		putchar('1');
	}
	For(j,0,n0-A[1]) putchar('0');
	puts("");
}