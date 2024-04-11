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
int T,n,m;
vector <int> ans;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void solve(int a)
{
	bool bl=0;
	for (int mask=0;mask<16;mask++)
	{
		int A=n-2,B=n-2,C=m-2,D=m-2;
		if (mask&1) A++;
		else C++;
		if (mask&2) A++;
		else D++;
		if (mask&4) B++;
		else C++;
		if (mask&8) B++;
		else D++;
		if (A%a==0&&B%a==0&&C%a==0&&D%a==0){bl=1;break;}
	}
	if (bl) ans.push_back(a);
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();m=read();
		int v=2*(n+m)-4;ans.clear();
		for (int i=1;i*i<=v;i++) if (v%i==0)
		{
			solve(i);
			if (i*i!=v) solve(v/i);
		}
		sort(ans.begin(),ans.end());
		printf("%lld ",len(ans));
		for (int i:ans) printf("%lld ",i);
		printf("\n");
	}
}