#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=1000005,mod=1000000007;
int n,len,g[N],f[N];
char s[N],c[N];

struct pam
{
	int p[N],tot,len[N],fail[N],d[N],nxt[N][30],fa[N];

	pam() {c[0]='*',tot=1,len[1]=-1,fail[0]=1;}
	
	void ins(int i,int ch)
	{
		int lst=p[i-1];
		while(ch!=c[i-len[lst]-1]-'a')
			lst=fail[lst];
		if(!nxt[lst][ch])
		{
			int k=lst;
			len[++tot]=len[lst]+2,lst=fail[lst];
			while(ch!=c[i-len[lst]-1]-'a') lst=fail[lst];
			fail[tot]=nxt[lst][ch];
			nxt[k][ch]=tot,lst=k;

			d[tot]=len[tot]-len[fail[tot]];
			if(d[tot]==d[fail[tot]]) fa[tot]=fa[fail[tot]];
			else fa[tot]=fail[tot];
		}
		p[i]=nxt[lst][ch];
	}
} t;

void inc(int &x,int y)
{
	if((x+=y)>=mod) x-=mod;
}

int main()
{
	scanf("%s",s+1),len=strlen(s+1);
	int head=1,tail=len;
	while(head<tail) c[++n]=s[head++],c[++n]=s[tail--];
	rep(i,1,n)
		t.ins(i,c[i]-'a');
	f[0]=1;
	rep(i,1,n)
		for(int p=t.p[i]; p; p=t.fa[p])
		{
			g[p]=f[i-t.len[t.fa[p]]-t.d[p]];
			if(t.d[p]==t.d[t.fail[p]]) inc(g[p],g[t.fail[p]]);
			if(!(i&1)) inc(f[i],g[p]);
		}
	printf("%d\n",f[n]);
	return 0;
}