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
LL gcd(LL a,LL b){return a==0?b:gcd(b%a,a);}
int n;
int main()
{
	n=read();LL a1=read();
	for(int i=2;i<=n;i++)
	{
		LL k=read();
		a1=gcd(a1,k);
	}
	LL ans=0;
	for(LL i=1;1LL*i*i<=a1;i++)if(!(a1%i))
	{
		++ans;
		if(1LL*i*i!=a1)++ans;
	}
	pr2(ans);
}