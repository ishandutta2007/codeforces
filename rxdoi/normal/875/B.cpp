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

const int N=300000+19;

int sum[N],vis[N];
int n,m,x;

void Add(int x){
	for (;x<=n;x+=x&-x) sum[x]++;
}
int Qry(int x){
	int res=0;
	for (;x;x-=x&-x) res+=sum[x];
	return res;
}

int main(){
	n=IN();
	m=n;
	printf("1 ");
	For(i,1,n+1){
		x=IN();
		vis[x]=1;
		Add(x);
		while (m>=1&&vis[m]) m--;
		printf("%d ",Qry(m)+1);
	}
	puts("");
}