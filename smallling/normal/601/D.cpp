#include<cstdio>
#include<cstring>

#define N 300010

using namespace std;

struct Trie{
	Trie *go[26];
	int size;
}*root[N],*cur,Pool[N*10];

struct lhy{
	int x,y,next;
}edge[2*N];

int n,c[N],ans,x,y,Ans,tot,son[N];
char s[N];

inline void add(int x,int y)
{
	edge[++tot].x=x;edge[tot].y=y;edge[tot].next=son[x];son[x]=tot;
}

Trie *merge(Trie *A,Trie *B)
{
	if(!A)return B;
	if(!B)return A;
	int nowsize=0;
	for(int i=0;i<26;i++)
	{
		if(A->go[i]&&B->go[i])A->go[i]=merge(A->go[i],B->go[i]);
		if(!A->go[i]&&B->go[i])A->go[i]=B->go[i];
		if(A->go[i])nowsize+=A->go[i]->size+1;
	}
	A->size=nowsize;
	return A;
}

void dfs(int x,int fa)
{
	int y;
	root[x]=++cur;
	Trie *now=++cur;
	for(int i=son[x];i;i=edge[i].next)
		if((y=edge[i].y)!=fa)
		{
			dfs(y,x);
			if(root[y]->size>=now->size)now=merge(root[y],now);
			else now=merge(now,root[y]);
		}
	root[x]->go[s[x]-'a']=now;
	root[x]->size=now->size;
	root[x]->size++;
	if(root[x]->size+c[x]>ans)ans=root[x]->size+c[x],Ans=0;
	if(root[x]->size+c[x]==ans)Ans++;
}

int main()	
{
	cur=Pool;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	scanf("%s",s+1);
	for(int i=1;i<n;i++)
		scanf("%d%d",&x,&y),add(x,y),add(y,x);
	dfs(1,0);
	printf("%d\n%d\n",ans,Ans);
}