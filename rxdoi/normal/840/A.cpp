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

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=200000+19;

int A[N],B[N],id[N],rk[N]; 
int n;

int cmp(int x,int y){
	return B[x]<B[y];
}

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1) B[i]=IN();
	For(i,1,n+1) id[i]=i;
	sort(id+1,id+n+1,cmp);
	For(i,1,n+1) rk[id[i]]=i;
	sort(A+1,A+n+1);
	For(i,1,n+1) printf("%d ",A[n-rk[i]+1]);
	puts("");
}