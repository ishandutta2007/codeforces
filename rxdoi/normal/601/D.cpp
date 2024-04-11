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

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

const int N=300000+19;

struct node{
	node *go[26];
	int key,sz;
} Nd[N*2],*rt[N],*cur=Nd;
char s[N];

node *Merge(node *A,node *B){
	if (!A) return B;
	if (!B) return A;
	//if (A->sz<B->sz) swap(A,B);
	A->key=A->sz=A->key||B->key;
	For(i,0,26){
		A->go[i]=Merge(A->go[i],B->go[i]);
		if (A->go[i]) A->sz+=A->go[i]->sz;
	}
	return A;
}

struct Edge{
	int y,nxt;
} E[N*2];
int las[N],val[N];
int n,cnt,res,num;

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
void dfs(int x,int fa){
	node *tmp=cur++;
	tmp->key=1;
	tmp->sz=1;
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			dfs(y,x);
			tmp=Merge(tmp,rt[y]);
		}
	rt[x]=cur++;
	rt[x]->go[s[x]-'a']=tmp;
	rt[x]->key=0;
	rt[x]->sz=tmp->sz;
	if (rt[x]->sz+val[x]>res) res=rt[x]->sz+val[x],num=0;
	if (rt[x]->sz+val[x]==res) num++;
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN();
	For(i,1,n+1) val[i]=IN();
	scanf("%s",s+1);
	For(i,1,n) Link(IN(),IN());
	dfs(1,-1);
	printf("%d\n",res);
	printf("%d\n",num);
}