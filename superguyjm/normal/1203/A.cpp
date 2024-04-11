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
const int MAXN=405;
int a[MAXN],ps[MAXN],n;
int main()
{
	int T=read();while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),ps[a[i]]=i;
		for(int i=n+1;i<=2*n;i++)a[i]=a[i-n];
		bool tf1=true,tf2=true;
		for(int i=ps[1];i<=ps[1]+n-1;i++)if(i-ps[1]+1!=a[i]){tf1=false;break;}
		for(int i=ps[1]+n;i>=ps[1]+1;i--)if(ps[1]+n-i+1!=a[i]){tf2=false;break;}
		tf1|=tf2;
		if(tf1)puts("YES");
		else puts("NO");
	}
}