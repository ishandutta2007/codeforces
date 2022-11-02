#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n,m,i,j,k,l,r,ll,rr,aim,sum,ans;
int trie[200005][26],fa[200005],ch[200005],tot;
int fail[200005],q[200005];
int son[200005],next[200005];
int st[200005],en[200005],ed[200005];
char s[200005];

void dfs(int x)
{
	if(x)st[x]=++tot;
	for(int i=son[x];i;i=next[i])dfs(i);
	if(x)en[x]=tot;
}

struct node
{
	int l,r,sum;
}t[10000005];
int root[200005],cnt;

void C(int &x,int l,int r)
{
	t[++cnt]=t[x];
	++t[x=cnt].sum;
	if(l==r)return;
	int mid=l+r>>1;
	if(aim<=mid)C(t[x].l,l,mid);
	else C(t[x].r,mid+1,r);
}

void Q(int x,int l,int r)
{
	if(l>=ll&&r<=rr)
	{
		sum+=t[x].sum;
		return;
	}
	int mid=l+r>>1;
	if(rr<=mid)Q(t[x].l,l,mid);
	else if(ll>mid)Q(t[x].r,mid+1,r);
		else Q(t[x].l,l,mid),Q(t[x].r,mid+1,r);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		l=strlen(s+1);
		k=0;
		for(j=1;j<=l;++j)
		{
			if(!trie[k][s[j]-'a'])
			{
				trie[k][s[j]-'a']=++tot;
				fa[tot]=k;
				ch[tot]=s[j]-'a';
			}
			k=trie[k][s[j]-'a'];
		}
		ed[i]=k;
	}
	q[rr=1]=0;
	for(i=0;i<=tot;++i)
	{
		k=q[++ll];
		for(j=0;j<26;++j)if(trie[k][j])q[++rr]=trie[k][j];
		if(k)
		{
			for(j=fail[fa[k]];j&&!trie[j][ch[k]];j=fail[j]);
			fail[k]=trie[j][ch[k]];
			if(fail[k]==k)fail[k]=0;
		}
	}
	for(i=1;i<=tot;++i)
	{
		next[i]=son[fail[i]];
		son[fail[i]]=i;
	}
	tot=0;
	dfs(0);
	for(i=1;i<=n;++i)
	{
		root[i]=root[i-1];
		for(j=ed[i];j;j=fa[j])
		{
			aim=st[j];
			C(root[i],1,tot);
		}
	}
	for(;m;--m)
	{
		scanf("%d%d%d",&l,&r,&k);
		ll=st[ed[k]];rr=en[ed[k]];
		sum=0;Q(root[r],1,tot);ans=sum;
		sum=0;Q(root[l-1],1,tot);ans-=sum;
		printf("%d\n",ans);
	}
}