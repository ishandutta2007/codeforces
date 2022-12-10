#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Pb push_back
using namespace std;

const int N=5000+19,Top=20000000;
int f[N][N],n,k;
char s[N];
string Ans;

int DP(int L,int R)
{
	if (~f[L][R]) return f[L][R];
	return f[L][R]=L>=R?1:(s[L]==s[R]&&DP(L+2,R-2));
}

//Trie
int son[Top][2],cnt[Top],Sum[Top],tot,x,t,y;

void DFS(int x)
{
	Sum[x]=cnt[x];
	For(i,0,2) if (int y=son[x][i]) DFS(y),Sum[x]+=Sum[y];
}
void DFS_2(int x)
{
	if (k<=cnt[x]) return;k-=cnt[x];
	For(i,0,2)
		if (int y=son[x][i])
			if (k>Sum[y]) k-=Sum[y];else {Ans.Pb(i+'a'),DFS_2(y);break;}
}

int main()
{
	memset(f,-1,sizeof(f));
	scanf("%s%d",s,&k);n=strlen(s);
	For(i,0,n) For(j,i,n) f[i][j]=DP(i,j);
	For(i,0,n)
	{
		x=0;
		For(j,i,n)
		{
			int &u=son[x][s[j]-'a'];
			if (!u) u=++tot;x=u;
			if (f[i][j]) cnt[x]++;
		}
	}
	DFS(0);
	DFS_2(0);
	puts(Ans.c_str());
}