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
    inline void Read(int& x) {
        char ch;
        while (blank(ch = nc()));
        if (IOerror) return;
        for (x = ch - '0';(ch = nc()) >= '0' && ch <= '9';x = x * 10 + ch - '0');
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
int n,m,ans,f[2001][2001],g[2001][2001];
const int mod=1e9+7;
signed main()
{
	Read(n);
	Read(m);
	for(int i=1;i<=m;i++)
		f[1][i]=1;
	for(int i=2;i<=n;i++)
		for(int l=2;l<=m;l++)
			f[i][l]=(f[i-1][l]+f[i][l-1]*2-f[i][l-2]+mod)%mod;
	for(int i=1;i<=n;i++)
		for(int l=2;l<=m;l++)
			g[i][l]=(g[i-1][l]+f[i][l])%mod;
	for(int i=1;i<=n;i++)
		for(int l=2;l<=m;l++)
			(ans+=f[i][l]*g[n-i+1][l]%mod*(m-l+1)%mod)%=mod;
	cout<<ans;
	return 0;
}