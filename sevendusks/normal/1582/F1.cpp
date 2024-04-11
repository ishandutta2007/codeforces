/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1e5+100;
int n,a[N],vi[512];
bitset <512> dp[N];
vector <int> p[512];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),p[a[i]].push_back(i);
	for (int i=0;i<512;i++) reverse(p[i].begin(),p[i].end());
	dp[0][0]=1;
	for (int i=0;i<=n;i++)
	{
		bitset <512> tmp;
		tmp.reset();
		for (int j=0;j<512;j++) if (dp[i][j]) tmp[j^a[i]]=1,vi[j^a[i]]=1;
		for (int j=a[i]+1;j<512;j++) if (!p[j].empty())
		{
			while (!p[j].empty()&&p[j].back()<=i) p[j].pop_back();
			if (!p[j].empty()) dp[p[j].back()]|=tmp;
		}
	}
	vector <int> ans;
	for (int i=0;i<512;i++) if (vi[i]) ans.push_back(i);
	printf("%d\n",len(ans));
	for (int i:ans) printf("%d ",i);
	printf("\n");
}