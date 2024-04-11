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

const int N=50000+19;
const int S=256;

struct Edge{
	int y,nxt;
} E[N*2];
int cal[N][S];
int las[N],fa[N],dep[N],A[N],top[N];
int n,cnt,tmp,res,q,x,y;

struct node{
	node *s[2];
	int val;
} Nd[1000000],*cur,*rt;

node *New(){
	return *cur=(node){0x0,0x0,0},cur++;
}

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
void dfs(int x){
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa[x]){
			fa[y]=x;
			dep[y]=dep[x]+1;
			dfs(y);
		}
}
void Work(int x){
	int y=x;
	cur=Nd;
	rt=New();
	For(i,0,S){
		node *u=rt;
		for (int num=A[y]>>8,j=7;~j;j--){
			node *&v=u->s[num>>j&1];
			if (!v) v=New();u=v;
			u->val=max(u->val,(A[y]&S-1)^i);
		}
		y=fa[y];
	}
	top[x]=y;
	For(i,0,S){
		node *u=rt;
		int num=0;
		for (int j=7;~j;j--)
			if (u->s[i>>j&1^1]){
				u=u->s[i>>j&1^1];
				num|=1<<j;
			} else{
				u=u->s[i>>j&1];
			}
		cal[x][i]=num<<8|u->val;
	}
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN(),q=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n) Link(IN(),IN());
	dep[1]=1;
	dfs(1);
	For(i,1,n+1)
		if (dep[i]>=S){
			Work(i);
		}
	while (q--){
		x=IN(),y=IN();
		tmp=0,res=0;
		while (dep[y]-dep[x]+1>=S){
			res=max(res,cal[y][tmp>>8]);
			y=top[y];
			tmp+=S;
		}
		while (dep[y]>=dep[x]){
			res=max(res,A[y]^tmp);
			y=fa[y];
			tmp++;
		}
		printf("%d\n",res);
	}
}