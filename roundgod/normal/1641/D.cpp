#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 7
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> P;
int n,m;
int a[MAXN][MAXM],w[MAXN];
int ord[MAXN];
vector<int> st;
int p[MAXM]={132190,223213,323123,432131,532133,621312};
unordered_map<ull,int> mp;
ull BASE=19260817;
bool cmp(int x,int y)
{
	return w[x]<w[y];
}
void add(int id)
{
	for(int i=1;i<(1<<m);i++)
	{
		int pcount=__builtin_popcount(i);
		ull h=0;
		int cnt=0;
		for(int j=0;j<m;j++) if(i&(1<<j)) {h=h*BASE+1LL*p[cnt]*a[id][j]; cnt++;}
		mp[h]++;
	}
}
void dec(int id)
{
	for(int i=1;i<(1<<m);i++)
	{
		ull h=0;
		int cnt=0;
		for(int j=0;j<m;j++) if(i&(1<<j)) {h=h*BASE+1LL*p[cnt]*a[id][j]; cnt++;}
		mp[h]--;
	}
}
int check(int id)
{
	int res=0;
	for(int i=1;i<(1<<m);i++)
	{
		ull h=0;
		int cnt=0;
		for(int j=0;j<m;j++) if(i&(1<<j)) {h=h*BASE+1LL*p[cnt]*a[id][j]; cnt++;}
		int pcount=__builtin_popcount(i);
		if(pcount&1) res+=mp[h]; else res-=mp[h];
	}
	return res;
}
void in(int &x)
{
    int ff=1;char c=getchar();x=0;
    while(c<'0'||c>'9'){if(c=='-')ff=-1;c=getchar();}
    while(c<='9'&&c>='0'){ x=(x<<1)+(x<<3)+c-'0';c=getchar();}
    x*=ff;
}
int main()
{
	in(n); in(m);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++) in(a[i][j]);
		sort(a[i],a[i]+m);
		in(w[i]);
	}
	for(int i=1;i<=n;i++) ord[i]=i;
	sort(ord+1,ord+n+1,cmp);
	int ans=2*INF+1;
	for(int i=1;i<=n;i++)
	{
		if(st.size()&&w[ord[i]]+w[st[0]]>=ans) break;
		if(!st.size()&&2*w[ord[i]]>=ans) break;
		int last=0;
		while(check(ord[i])<(int)st.size())
		{
			int v=st.back(); st.pop_back(); last=v;
			dec(v);
		}
		if(last) ans=min(ans,w[ord[i]]+w[last]);
		st.push_back(ord[i]); add(ord[i]);
	}
	if(ans==2*INF+1) puts("-1"); else printf("%d\n",ans);
	return 0;
}