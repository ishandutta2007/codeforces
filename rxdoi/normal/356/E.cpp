#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Mid (L+R>>1)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=100000+19,B=10007;
typedef unsigned long long Ull;
typedef long long LL;
char s[N];
int c[26][N],n;
bool f[N][20];
Ull h[N],g[N];
LL v[N],Ans,tmp,Res;

Ull Hash(int L,int R) {return h[R]-h[L-1]*g[R-L+1];}
int Calc(int L,int R,int v) {return c[v][R]-c[v][L-1];}
void DFS(int l,int r,Ull H)
{
	int L,R,Len=r-l+1;
	tmp+=1LL*Len*Len;
	L=l,R=r+1+(r-l+1);
	if (R<=n&&Hash(Mid+1,R)==H&&Calc(Mid+1,R,s[Mid])==0) DFS(L,R,(H*B+s[Mid])*g[R-Mid]+Hash(Mid+1,R));
	L=l-1-(r-l+1),R=r;
	if (L>=1&&Hash(L,Mid-1)==H&&Calc(L,Mid-1,s[Mid])==0) DFS(L,R,(Hash(L,Mid-1)*B+s[Mid])*g[R-Mid]+H);
}

int main()
{
	scanf("%s",s+1);n=strlen(s+1);

	For(i,1,n+1) s[i]-='a';
	For(i,1,n+1) h[i]=h[i-1]*B+s[i];
	g[0]=1;For(i,1,n+1) g[i]=g[i-1]*B;
	For(i,0,26) For(j,1,n+1) c[i][j]=c[i][j-1]+(s[j]==i);

	for (int t=1,k=0;t<=n;t=t*2+1,k++)
		for (int L=1;L+t-1<=n;L++)
		{
			int R=L+t-1,Len=R-L+1;
			if (!k||f[L][k-1]&&f[Mid+1][k-1]&&Hash(L,Mid-1)==Hash(Mid+1,R)&&Calc(L,R,s[Mid])==1)
			{
				Ans+=1LL*Len*Len;
				f[L][k]=1,v[L]+=1LL*Len*Len,v[R+1]-=1LL*Len*Len;
			}
		}
	For(i,1,n+1) v[i]+=v[i-1];
	For(i,1,n+1) For(j,0,26)
	{
		tmp=Ans-v[i];
		for (int t=1,k=0;i-t/2>=1&&i+t/2<=n;t=t*2+1,k++)
		{
			int L=i-t/2,R=i+t/2;
			if (!k||f[L][k-1]&&f[Mid+1][k-1]&&Hash(L,Mid-1)==Hash(Mid+1,R)&&Calc(L,Mid-1,j)+Calc(Mid+1,R,j)==0)
				DFS(L,R,(Hash(L,Mid-1)*B+j)*g[R-Mid]+Hash(Mid+1,R));else break;
		}
		Res=max(Res,tmp);
	}
	printf("%I64d\n",Res);
}