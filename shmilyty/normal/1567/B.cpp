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
int t,a,b,x,f[300001];
void solve()
{
	a=read();
	b=read();
	x=f[a-1];
	if(x==b)
		cout<<a<<endl;
	elif((x^b)==a)
		cout<<a+2<<endl;
	else
		cout<<a+1<<endl;
}
signed main()
{
	t=read();
	for(int i=1;i<=300000;i++)
		f[i]=(f[i-1]^i); 
	while(t--)
		solve();
	return 0;
}