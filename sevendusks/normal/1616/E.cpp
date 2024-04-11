 /*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define m_k make_pair
#define int long long 
#define len(a) (int)a.size()
using namespace std;
const int N=1e5+100;
int TT,n,p[N];
char s[N],t[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
struct bit//
{
	int sh[N];
	inline void init(int n){memset(sh,0,(n+10)*sizeof(int));}
	int lowbit(int x){return x&(-x);}
	void change(int x,int v){while(x<=n)sh[x]+=v,x+=lowbit(x);}
	int query(int x){int ans=0;while(x)ans+=sh[x],x-=lowbit(x);return ans;}
}T;

signed main()
{
	TT=read();
	while (TT--)
	{
		n=read();
		scanf("%s%s",s+1,t+1);
		vector <int> wh[26];
		for (int i=1;i<=n;i++) wh[s[i]-'a'].push_back(i);
		for (int i=0;i<26;i++) reverse(wh[i].begin(),wh[i].end());
		int ok=n;
		for (int i=1;i<=n;i++)
		{
			int x=t[i]-'a';
			if (wh[x].empty()){ok=i;break;}
			p[i]=wh[x].back();wh[x].pop_back();
		}
		for (int i=0;i<26;i++) wh[i].clear();
		for (int i=1;i<=n;i++) wh[s[i]-'a'].push_back(i);
		for (int i=0;i<26;i++) reverse(wh[i].begin(),wh[i].end());
		T.init(n);
		for (int i=1;i<=n;i++) T.change(i,1);
		int ans=inf,sum=0;
		for (int i=1;i<=ok;i++)
		{
			int x=t[i]-'a';
			for (int j=0;j<x;j++) if (!wh[j].empty())
			{
				int y=wh[j].back(),pos=T.query(y)-1;
				ans=min(ans,sum+pos);
			}
			if (i==ok) break;
			wh[x].pop_back();
			sum+=T.query(p[i])-1;
			T.change(p[i],-1);
		}
		if (ans==inf) puts("-1");
		else printf("%lld\n",ans);
	}
}