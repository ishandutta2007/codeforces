
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define endl "\n"
#define rd(x) x=read()
#define wt(x) write(x)
using namespace std;
const int N=2e5+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int n,a[N];
char s[N];
bool t1[N],t2[N];
int L,R;
int main()
{
    rd(n);for (int i=1;i<=n;i++) rd(a[i]);
    scanf("%s",s+1),sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) t2[i]=(s[i]=='R'),L+=(i>1&&t2[i]==t2[i-1]);
    t1[n]=t2[n];for (int i=n-1;i>=1;i--) t1[i]=(t1[i+1]^1);
    R=L+1,printf("%d %c\n",a[R],t1[R]?'R':'L'),R++;
    for (int i=2;i<=n;i++) if (t1[R-1]^t2[i]) printf("%d %c\n",a[R],t1[R]?'R':'L'),R++;else printf("%d %c\n",a[L],t1[L]?'R':'L'),L--;
}