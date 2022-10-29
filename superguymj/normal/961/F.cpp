#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=2000005;
int n,fa[N];
char s[N],str[N];

int getfa(int x)
{
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}

void merge(int x,int y)
{
	x=getfa(x),y=getfa(y);
	fa[x]=y;
}

struct pam
{
	int fail[N],nxt[N][26],p[N],len[N],tot;

	pam() {s[0]='*',tot=1,len[1]=-1,fail[0]=1;}
	
	void ins(int i)
	{
		int lst=p[i-1];
		while(s[i]!=s[i-len[lst]-1]) lst=fail[lst];
		if(!nxt[lst][s[i]-'a'])
		{
			int k=fail[lst];
			len[++tot]=len[lst]+2;
			while(s[i]!=s[i-len[k]-1]) k=fail[k];
			fail[tot]=nxt[k][s[i]-'a'];
			nxt[lst][s[i]-'a']=tot;
		}
		p[i]=nxt[lst][s[i]-'a'];
	}
	
	void solve(int x)
	{
		int L=n/2-x*2+2;
		x=n-(x*2-1)+1;
		int u=getfa(p[x]);
		while(u)
		{
			if(len[u]%4==2 && len[u]/2<L)
			{
				printf("%d ",len[u]/2);
				return;
			}
			merge(u,fail[u]),u=getfa(u);
		}
		printf("-1 ");
	}
} t;

int main()
{
	scanf("%d%s",&n,str+1);
	rep(i,1,n) str[i+n]=str[i];
	int head=1,tail=n*2;
	for(n=0; head<tail; s[++n]=str[head++],s[++n]=str[tail--]);
	reverse(s+1,s+1+n);
	rep(i,1,n)
		t.ins(i);
	rep(i,1,t.tot) fa[i]=i;
	rep(i,1,(n/2+1)/2)
		t.solve(i);
	puts("");
	return 0;
}