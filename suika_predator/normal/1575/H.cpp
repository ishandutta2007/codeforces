#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
const int maxn = 1050;

int n,m,K;
int findfa(int fa[],const int x)
{
	return fa[x]==x?x:fa[x]=findfa(fa,fa[x]);
}
int fa[maxn][maxn];
int a[maxn][maxn];
*/

const int maxn = 505;
inline void down(int &a,const int &b){ if(a==-1||a>b)a=b; }

int n,m;
char A[maxn],B[maxn];

int f[2][maxn][maxn];
int ans[maxn];
struct AC
{
	int root,tot;
	int son[maxn][2],fail[maxn],ed[maxn];
	int newnode()
	{
		++tot;
		memset(son[tot],0,sizeof son[tot]);
		fail[tot]=0;
		ed[tot]=0;
		return tot;
	}
	void init()
	{
		tot=0;
		root=newnode();
	}
	queue<int>q;
	void build(char str[],int len)
	{
		int x=root;
		for(int i=0;i<len;i++)
		{
			int c=str[i]-'0';
			if(!son[x][c]) son[x][c]=newnode();
			x=son[x][c];
			
			if(i==len-1) ed[x]=1;
		}
		
		q.push(root);
		while(!q.empty())
		{
			x=q.front(); q.pop();
			int fl=fail[x];
			if(ed[fl]) ed[x]=1;
			
			for(int i=0;i<2;i++)
			{
				int &y=son[x][i];
				if(y)
				{
					if(fl) fail[y]=son[fl][i];
					else fail[y]=root;
					q.push(y);
				}
				else 
				{
					if(fl) y=son[fl][i];
					else y=root;
				}
			}
		}
	}
	void dp(char str[],int len,int uj)
	{
		memset(f,-1,sizeof f);
		int now=0;
		f[now][root][0]=0;
		for(int i=0;i<len;i++)
		{
			now=!now;
			int cc=str[i]-'0';
			for(int x=1;x<=tot;x++) for(int j=0;j<=uj;j++) if(f[!now][x][j]!=-1)
			{
				int &temp=f[!now][x][j];
				
				int y=son[x][cc];
				down(f[now][y][j+ed[y]],temp+0);
				y=son[x][!cc];
				down(f[now][y][j+ed[y]],temp+1);
				
				temp=-1;
			}
		}
		
		for(int j=0;j<=uj;j++) ans[j]=-1;
		for(int x=1;x<=tot;x++) for(int j=0;j<=uj;j++) if(f[now][x][j]!=-1)
		{
			down(ans[j],f[now][x][j]);
		}
	}
}ac;

int main()
{
	ios_base::sync_with_stdio(false);
	/*
	cin>>n>>m>>K;
	for(int j=1;j<=m;j++) fa[j][n+1]=n+1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==1) fa[j][i]=i;
			else if(a[i][j]==2) fa[j][i]=i+1;
			else fa[j][i]=i;
		}
	}
	
	for(int ki=1;ki<=K;ki++)
	{
		int ci; cin>>ci;
		int i=1,j=ci;
		while(i<n)
		{
			i=findfa(fa[j],i);
			if(i<=n)
			{
				int cc=a[i][j];
				
				a[i][j]=2;
				fa[j][i]=i+1;
				if(cc==1) j++;
				else j--;
			}
		}
		cout<<j<<" \n"[ki==K];
	}
	*/
	
	cin>>n>>m;
	cin>>(A)>>(B);
	ac.init();
	ac.build(B,m);
	ac.dp(A,n,n-m+1);
	for(int i=0;i<=n-m+1;i++) cout<<ans[i]<<" \n"[i==n-m+1];
	
	return 0;
}