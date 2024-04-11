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
	freopen((s+"in").c_str(),"r",stdin);
	freopen((s+"out").c_str(),"w",stdout);
}
const int INF=4e18;
int n,sum,cnt,ans,a[300001]; 
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		sum+=a[i]/1000;
		if(a[i]==1000)
			cnt++; 
	}
	ans=sum*10/11;
	if(sum<=11)
		ans=sum-a[n]/1000;
	if(cnt==0&&(ans&1))
		ans--;
	cout<<sum*1000-ans*100;
	return 0;
}