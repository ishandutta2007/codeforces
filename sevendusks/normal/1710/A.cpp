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
const int N=1e5+100;
int T,n,m,k,a[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();m=read();k=read();
		for (int i=1;i<=k;i++) a[i]=read();
		vector <int> v;
		for (int i=1;i<=k;i++) if (a[i]>=2*n) v.push_back(a[i]/n);
		sort(v.begin(),v.end());reverse(v.begin(),v.end());
		bool bl=0;
		for (int i=0,sum=0;i<len(v);i++)
		{
			if ((i+1)*2>m) break;
			sum+=v[i];
			if (sum>=m){bl=1;break;}
		}
		swap(n,m);v.clear();
		for (int i=1;i<=k;i++) if (a[i]>=2*n) v.push_back(a[i]/n);
		sort(v.begin(),v.end());reverse(v.begin(),v.end());
		for (int i=0,sum=0;i<len(v);i++)
		{
			if ((i+1)*2>m) break;
			sum+=v[i];
			if (sum>=m){bl=1;break;}
		}
		if (bl) printf("Yes\n");
		else printf("No\n");
	}
}