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

const int N=2e5+19;

struct Edge{
	int y,nxt;
} E[N*2];
int las[N],fa[N],A[N];
int n,cnt,mx,pt,x,tmp,len;

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
int calc(int val){
	while (val%2==0) val/=2;
	return val;
}
void dfs1(int x,int dis){
	if (dis>mx){
		mx=dis;pt=x;
	}
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa[x]){
			fa[y]=x;
			dfs1(y,dis+1);
		}
}
void dfs2(int x,int fa,int dis){
	int c=0;
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			c++;
			dfs2(y,x,dis+1);
		}
	if (!c){
		if (tmp==-1){
			tmp=dis;
		} else if (tmp!=dis){
			puts("-1");
			exit(0);
		}
	}
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN();
	For(i,1,n) Link(IN(),IN());
	dfs1(1,0);
	mx=0;
	memset(fa,0,sizeof(fa));
	dfs1(pt,0);
	for (int i=pt;i;i=fa[i]) len++;
	len/=2;
	for (int i=pt;len;len--) x=i=fa[i];
	for (int i=las[x],y;~i;i=E[i].nxt){
		y=E[i].y;
		tmp=-1;
		dfs2(y,x,1);
		A[++*A]=tmp;
	}
	sort(A+1,A+*A+1);
	*A=unique(A+1,A+*A+1)-A-1;
	if (*A>2){
		puts("-1");
		return 0;
	}
	if (*A==2){
		printf("%d\n",calc(A[1]+A[2]));
	} else{
		printf("%d\n",calc(A[1]));
	}
}