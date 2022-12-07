#include<bits/stdc++.h>
#define cmax(a,b) a=max(a,b)
using namespace std;
int rd()
{
	int rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
int rc()
{
	char c=getchar();
	while(!((c>='a'&&c<='z')||c=='?')) c=getchar();
	if(c=='?') return 0;
	else return c-'a'+1;
}
const int N=3e5+50,C=30;
int n,Q,pd=1,cdt=-1,cnt=0;
int fa[N],las[N],ds[N],dy[N],fw[N][C],f[N][C],g[N],det[N],len[N],son[N][2];
void oup(int x,int c)
{
	f[x][c]=0;
	if(son[x][0]) cmax(f[x][c],f[son[x][0]][c]+fw[son[x][0]][c]);
	if(son[x][1]) cmax(f[x][c],f[son[x][1]][c]+fw[son[x][1]][c]);
}
void mup(int x)
{
	int i;
	for(i=1;i<=26;i++) 
	{
		oup(x,i);
		g[x]+=f[x][i];
	}
}
void update(int x,int c,int der)
{
	//printf("update%d %d %d\n",x,c,der);
	if(c==0) return ;
	int pos,a,b;
	fw[x][c]+=der;
	while(x!=1)
	{
		pos=fa[x];
		if(g[pos]>len[pos]) cnt--; 
		a=f[pos][c];
		oup(pos,c);
		b=f[pos][c];
		g[pos]+=b-a;
		if(g[pos]>len[pos]) cnt++;
		x=pos;
	}
}
int main()
{
	int i,rx,bx,x,c,ans;
	n=rd();Q=rd();
	det[1]=1;
	for(i=2;i<=n;i++)
	{
		//printf("#%d\n",i);
		fa[i]=rd();las[i]=rc();
		det[i]=det[fa[i]]+1;
		ds[fa[i]]++;
	}
	for(i=1;i<=n;i++)
	{
		if(ds[i]==0)
		{
			if(cdt==-1) cdt=det[i];
			if(det[i]!=cdt) pd=0;
		}
	}
	if(pd==0)
	{
		while(Q--) puts("Fou");
		return 0;
	}
	for(i=1;i<=n;i++) len[i]=cdt-det[i];
	for(i=n;i>=2;i--)
	{
		if(dy[i]) continue;
		dy[i]=i;
		x=i;
		while(fa[x]!=1&&ds[fa[x]]==1) 
		{
			fw[i][las[x]]++;x=fa[x];dy[x]=i;
		}
		fw[i][las[x]]++;x=fa[x];
		fa[i]=x;
		if(!son[x][0]) son[x][0]=i;
		else son[x][1]=i;
	}
	dy[1]=1;
	for(i=n;i>=1;i--)
	{
		if(dy[i]==i) 
		{
			mup(i);
			if(g[i]>len[i]) cnt++;
		}
	}
	while(Q--)
	{
		rx=rd();c=rc();
		bx=dy[rx];
		update(bx,las[rx],-1);
		update(bx,c,1);
		if(cnt>0) puts("Fou");
		else
		{
			ans=0;
			//printf("P%d %d\n",f[1][1],g[1]);
			for(i=1;i<=26;i++)
			{
				ans+=i*(f[1][i]+len[1]-g[1]);
			}
			printf("Shi %d\n",ans);
		}
		las[rx]=c;
	}
	return 0;
}