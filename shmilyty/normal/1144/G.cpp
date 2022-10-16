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
int n,l1,l2,a[200001],b[200001]; 
signed main()
{
	Read(n);
	for(int i=1;i<=n;i++)
		Read(a[i]);
	l1=-1;
	l2=INF;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=l1&&a[i]>=l2)
		{
			puts("NO");
			return 0;
		}
		if(a[i]<=l1&&a[i]<l2)
			b[i]=1;
		if(a[i]>l1&&a[i]<l2)
			if(a[i+1]<=a[i])
				b[i]=1;
		if(b[i])
			l2=min(l2,a[i]);
		else
			l1=max(l1,a[i]);
	}
	puts("YES");
	for(int i=1;i<=n;i++)
		cout<<b[i]<<" ";
	return 0;
}