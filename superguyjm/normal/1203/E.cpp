#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<ctime>
#include<map>
#include<bitset>
#include<set>
#define LL long long
#define mp(x,y) make_pair(x,y)
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;
inline LL read()
{
	LL f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int stack[20];
template<typename T>inline void write(T x)
{
	if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int top=0;
    while(x)stack[++top]=x%10,x/=10;
    while(top)putchar(stack[top--]+'0');
}
template<typename T>inline void pr1(T x){write(x);putchar(' ');}
template<typename T>inline void pr2(T x){write(x);putchar('\n');}
const int MAXN=150005;
int a[MAXN],n;
int f[MAXN][3],s[MAXN];

int lowbit(int x){return x&-x;}
void modify(int x,int c)
{
	if(!x)return ;
	for(;x<MAXN;x+=lowbit(x))s[x]=max(s[x],c);
}
int qry(int x){int ret=0;for(;x>=1;x-=lowbit(x))ret=max(ret,s[x]);return ret;}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	int ans=0;
	modify(a[1]-1,1);modify(a[1],1);modify(a[1]+1,1);
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j>=-1;j--)
		{
			int c=a[i]+j,k=j+1;
			f[i][j+1]=qry(c-1)+1;if(!c)f[i][j+1]=0;
			modify(c,f[i][j+1]);
		}
	}
	f[1][0]=f[1][1]=f[1][2]=1;
	if(!(a[1]-1))f[1][0]=0;
	for(int i=1;i<=n;i++)for(int j=0;j<=2;j++)ans=max(ans,f[i][j]);
	pr2(ans);
}