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
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

int IN()
{
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=1000+19;

int f[N*N];
int A[N];
int n,Min,Max,k;

int main()
{
	n=IN();k=IN();
	For(i,1,n+1) A[i]=IN();
	sort(A+1,A+n+1);
	Min=k*A[1];
	Max=k*A[n];
	For(i,2,n+1) A[i]-=A[1];
	memset(f,60,sizeof(f));
	f[Min]=0;
	For(i,2,n+1)
		for (int j=Min+A[i];j<=Max;j++) f[j]=min(f[j],f[j-A[i]]+1);
	For(i,Min,Max+1) if (f[i]<=k) printf("%d ",i);puts("");
}