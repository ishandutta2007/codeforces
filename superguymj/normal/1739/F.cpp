#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=4005,M=5005;
int n,tot,head,tail,q[N],s[N],t[N][20],f[N][M];
int m,ans,fail[N],nxt[N][M],siz[N],ch[N][M];
string str;

void modify()
{
	s[head=tail=str.length()]=str[0];
	int p=head;
	rep(i,1,(int)str.length()-1)
	{
		if(p+1<=tail && s[p+1]==str[i]) ++p;
		else if(p-1>=head && s[p-1]==str[i]) --p;
		else if(p==tail) s[++p]=str[i],++tail;
		else if(p==head) s[--p]=str[i],--head;
		else return;
	}
	int x=1;
	rep(i,head,tail)
	{
		int c=s[i]-'a';
		if(t[x][c]) x=t[x][c];
		else t[x][c]=++tot,x=tot;
	}
	siz[x]+=m;
	x=1;
	repd(i,tail,head)
	{
		int c=s[i]-'a';
		if(t[x][c]) x=t[x][c];
		else t[x][c]=++tot,x=tot;
	}
	siz[x]+=m;
}

void acam()
{
	rep(i,0,11) t[0][i]=1;
	q[head=tail=0]=1;
	while(head<=tail)
	{
		int x=q[head++];
		rep(i,0,11)
			if(t[x][i]) fail[t[x][i]]=t[fail[x]][i],q[++tail]=t[x][i];
			else t[x][i]=t[fail[x]][i];
		siz[x]+=siz[fail[x]];
	}
}

void dfs(int x,int s)
{
	if(s==0) return;
	putchar('a'+ch[x][s]);
	dfs(nxt[x][s],s^(1<<ch[x][s]));
}

void dp()
{
	memset(f,-1,sizeof(f));
	f[1][0]=0;
	int S=(1<<12)-1;
	rep(i,0,S)
	{
		rep(x,1,tot) if(f[x][i]>=0)
		{
			f[x][i]+=siz[x];
			rep(c,0,11) if(!(i&(1<<c)))
			{
				if(f[t[x][c]][i|(1<<c)]<f[x][i])
				{
					f[t[x][c]][i|(1<<c)]=f[x][i];
					nxt[t[x][c]][i|(1<<c)]=x;
					ch[t[x][c]][i|(1<<c)]=c;
				}
			}
		}
	}
	ans=-1;
	int tmp=0;
	rep(x,1,tot) if(f[x][S]>ans) ans=f[x][S],tmp=x;
	dfs(tmp,S);
}

int main()
{
//	freopen("f.in","r",stdin);
	scanf("%d",&n);
	tot=1;
	rep(i,1,n)
	{
		scanf("%d",&m);
		cin>>str;
		modify();
	}
	acam();
	dp();
	return 0;
}