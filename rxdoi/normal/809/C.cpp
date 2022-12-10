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

int cal(int x,int a,int k){
	if (a/x>k/x) return 0;
	if (a/x<k/x){
		return (1ll*(a/x)*x*x+1ll*x*(x+1)/2)%p;
	}
	k%=x;
	return (1ll*(a/x)*x*(k+1)+1ll*(k+1)*(k+2)/2)%p;
}
int calc(int lx,int rx,int ly,int ry,int k){
	if ((rx^lx)>(ry^ly)) swap(lx,ly),swap(rx,ry);
	return 1ll*(rx^lx)*cal(ry^ly,lx^ly,k)%p;
}
int calc(int x,int y,int k){
	int lx=0,res=0;
	for (int i=30;~i;i--)
		if (x>>i&1){
			int ly=0;
			for (int j=30;~j;j--)
				if (y>>j&1){
					res=(res+calc(lx,lx|1<<i,ly,ly|1<<j,k))%p;
					ly^=1<<j;
				}
			lx^=1<<i;
		}
	return res;
}

int X1,Y1,X2,Y2,k,res;

int main(){
	for (int q=IN();q--;){
		X1=IN(),Y1=IN(),X2=IN(),Y2=IN(),k=IN()-1;
		res=0;
		res=(res+calc(X2,Y2,k))%p;
		res=(res-calc(X2,Y1-1,k)+p)%p;
		res=(res-calc(X1-1,Y2,k)+p)%p;
		res=(res+calc(X1-1,Y1-1,k))%p;
		printf("%d\n",res);
	}
}