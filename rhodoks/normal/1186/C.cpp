#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 2100000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

char s[MAXN],t[MAXN];
int sum[MAXN];
int main()
{
	cin>>s>>t;
	int ls=strlen(s);
	int lt=strlen(t);
	int t1=0;
	int t2=0;
	for (int i=0;i<lt;i++)
		t1+=(t[i]=='1');
	for (int i=0;i<lt;i++)
		t2+=(s[i]=='1');
	int ans=((t1+t2)%2==0);
	for (int i=lt;i<ls;i++)
	{
		t2+=(s[i]=='1');
		t2-=(s[i-lt]=='1');
		ans+=((t1+t2)%2==0);
	}
	cout<<ans;
	return ~~(0^_^0);
}