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
    inline int read() {
		int x=0;
        char ch;
        while (blank(ch = nc()));
        if (IOerror) return 0;
        for (x = ch - '0';(ch = nc()) >= '0' && ch <= '9';x = x * 10 + ch - '0');
        return x;
    }//be careful with the negitives!!!
#undef BUF_SIZE
};
using namespace fastIO;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
int t,n,ans;
vector<int> v,v1;
void solve()
{
	n=read();
	v.clear();
	while(n)
	{
		v.push_back(n%10);
		n/=10;
	}
	n=v.size();
	ans=0;
	for(int i=0;i<(1<<n);i++)
	{
		if(i&1)
			continue;
		if((i>>1)&1)
			continue;
		v1=v;
		bool ok=1;
		for(int l=n-1;l>=2;l--)
			if((i>>l)&1)
			{
				if(!v1[l])
				{
					ok=0;
					break;
				}
				v1[l]--;
				v1[l-2]+=10;
			}	
		if(!ok)
			continue;
		int cnt=1;
		for(int l:v1)
			if(l<=9)
				cnt*=(l+1);
			else
				cnt*=(18-l+1);
		ans+=cnt;
	}
	cout<<ans-2<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve(); 
	return 0;
}