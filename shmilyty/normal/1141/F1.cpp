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
		int x=0,flag=1;
        char ch;
        while (blank(ch = nc()));
        if (IOerror) return 0;
        if(ch=='-')
        {
        	flag=-1;
      		ch=nc();
		}
        for (x = ch - '0';(ch = nc()) >= '0' && ch <= '9';x = x * 10 + ch - '0');
        return x*flag;
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
map<int,vector<pair<int,int> > > mp;
int n,sum,ans,a[1501];
bool cmp(pair<int,int> x,pair<int,int> y)
{
	return x.second<y.second;
}
signed main()
{
	n=Read();
	for(int i=1;i<=n;i++)
		a[i]=Read();
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	for(int i=1;i<=n;i++)
		for(int l=i;l<=n;l++)
			mp[a[l]-a[i-1]].push_back({i,l});
	for(auto &i:mp)
	{
		sort(ALL(i.second),cmp);
		int cnt=0,lst=0;
		for(auto l:i.second)
			if(l.first>lst)
			{
				lst=l.second;
				cnt++;
			}
		if(cnt>ans)
		{
			ans=cnt;
			sum=i.first;
		}
	}
	cout<<ans<<endl;
	int lst=0;
	for(auto i:mp[sum])
		if(i.first>lst)
		{
			cout<<i.first<<" "<<i.second<<endl;
			lst=i.second;
		}
	return 0;
}