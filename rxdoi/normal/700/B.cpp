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

const int N=200000+19;

struct Edge{
	int y,nxt;
} E[N*2];
int las[N],sz[N];
int cnt,n,k;
ll res;

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
void dfs(int x,int fa){
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			dfs(y,x);
			sz[x]+=sz[y];
		}
	res+=min(sz[x],2*k-sz[x]);
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN(),k=IN();
	For(i,0,2*k) sz[IN()]=1;
	For(i,1,n) Link(IN(),IN());
	dfs(1,-1);
	printf("%I64d\n",res);
}