//114514min
#include "bits/stdc++.h"
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,q,i,j;
		string s;
		cin>>n>>m>>s;
		vector<int> r(n*m+1),ans(n*m),rr(n*m),sum(n*m+1);
		for (j=0;j<m;j++)
		{
			for (i=0;i<n;i++) if (s[i*m+j]=='1') break;
			if (i!=n) ++r[i*m+j];
		}
		q=n*m;
		//for (i=0;i<q;i++) cerr<<r[i]<<" \n"[i==q-1];
		int cnt=0;
		for (i=0;i<q;i++) sum[i+1]=sum[i]+(s[i]-'0');
		for (i=m-1;i<q;i++) rr[i]+=(sum[i+1]>sum[i-m+1]);
		//for (i=0;i<q;i++) cerr<<rr[i]<<" \n"[i==q-1];
		for (i=0;i<1;i++)
		{
			for (j=i*m;j<(i+1)*m-1;j++) if (s[j]=='1') break;
			//dbg(i,j);
			for (;j<(i+1)*m-1;j++) ++rr[j];
		}
		for (i=1;i<q;i++) r[i]+=r[i-1];
		for (i=m;i<q;i++) rr[i]+=rr[i-m];
		for (i=0;i<q;i++) cout<<r[i]+rr[i]<<" \n"[i==q-1];
	}
}