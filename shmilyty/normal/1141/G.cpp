#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
namespace fastIO {
#define BUF_SIZE 100000
    bool IOerror = 0;
    inline char nc() {
        static char buf[BUF_SIZE], * p1 = buf + BUF_SIZE, * pend = buf + BUF_SIZE;
        if (p1 == pend) {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if (pend == p1) {
                IOerror = 1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    inline int Read() {
		int x=0;
        char ch;
        while (blank(ch = nc()));
        if (IOerror) return 0;
        for (x = ch - '0';(ch = nc()) >= '0' && ch <= '9';x = x * 10 + ch - '0');
        return x;
    }
#undef BUF_SIZE
};
using namespace fastIO;
void fileio(const string &s)
{
	freopen((s+"in").c_str(),"r",stdin);
	freopen((s+"out").c_str(),"w",stdout);
}
const int INF=4e18;
struct node{
	int to,nxt;
}edge[400001];
int n,k,cnt=1,col[200001],d[200001],head[200001];
void add(int x,int y)
{
	edge[++cnt]={y,head[x]};
	head[x]=cnt;
	d[y]++;
}
bool check(int x)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(d[i]>x)
			cnt++;
	return (cnt<=k);
}
void dfs(int x,int fa,int lst,int tot)
{
	if(d[x]>tot)
	{
		for(int i=head[x];i;i=edge[i].nxt)
			if(edge[i].to!=fa)
			{
				col[i/2]=1;
				dfs(edge[i].to,x,1,tot);
			}
		return ;
	}
	int c=0;
	for(int i=head[x];i;i=edge[i].nxt)
		if(edge[i].to!=fa)
		{
			c++;
			if(c==lst)
				c++;
			col[i/2]=c;
			dfs(edge[i].to,x,c,tot);
		}
}
signed main()
{
	n=Read();
	k=Read();
	for(int i=1;i<n;i++)
	{
		int x=Read(),y=Read();
		add(x,y);
		add(y,x);
	}
	int l=1,r=n-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	cout<<l<<endl;
	dfs(1,0,0,l);
	for(int i=1;i<n;i++)
		cout<<col[i]<<" ";
	return 0;
}