/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100;
int T,n,a[N];
bool bl;
map <int,int> mp;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void dfs(int x)
{
	if (!bl) return;
	if (mp.count(x)&&mp[x]>0){mp[x]--;return;}
	if (x==1){bl=0;return;}
	dfs(x/2);dfs((x+1)/2);
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		mp.clear();
		for (int i=1;i<=n;i++) a[i]=read(),mp[a[i]]++;
		bl=1;
		dfs(accumulate(a+1,a+1+n,0ll));
		if (bl) puts("YES");
		else puts("NO");
	}
}