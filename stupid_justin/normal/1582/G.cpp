
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define endl "\n"
#define ls (rt<<1)
#define rs (rt<<1|1)
using namespace std;
const int N=1e6+5;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if (x<0){putchar('-');x=-x;}if (x>=10)write(x/10);putchar(x%10+'0');}
long long ans;
int n;
int a[N],b[N];
int p[N];
int stk[N],top;
int num[N];
vector<int> v[N];
char t[N];
void add(int x,int i){b[i]=i;while (x>1) v[p[x]].push_back(i),x/=p[x];}
void del(int x,int i)
{
	b[i]=i;
	while(x>1)
	{
		if (v[p[x]].empty()){b[i]=0;return;}
		b[i]=min(b[i],v[p[x]].back());
		v[p[x]].pop_back();x/=p[x];
	}
}
signed main()
{
    rd(n);for (int i=1;i<=n;i++) rd(a[i]);scanf("%s",t+1);
	for (int i=2;i<N;i++) if (!p[i]){p[i]=i;for (int j=i;j<N;j+=i) p[j]=i;}
	for (int i=1;i<=n;i++) if (t[i]=='*') add(a[i],i);else del(a[i],i);
	for (int i=n;i>=1;i--)
	{
		int cnt=1;
		while (top>0 && stk[top]>=b[i]) cnt+=num[top],top--;
		stk[++top]=b[i];num[top]=cnt;
		if (i==b[i]) ans+=cnt; 
	}
    cout<<ans<<"\n";
}