#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

char s[MAXN];
int n;
void work()
{
	cin>>n;
	cin>>s;
	if (s[0]=='L')
		s[0]=0;
	else
		s[0]=1;
	for (int i=1;i<n;i++)
		if (s[i]=='L')
			s[i]=0^s[0];
		else
			s[i]=1^s[0];
	s[0]=0;
	//for (int i=0;i<n;i++)
	//	WRT((int)s[i])
	int pos=0;
	int ans=0;
	for (pos=0;pos<n;pos++)
		if (s[pos]==1)
			break;
	if (pos==n)
	{
		cout<<(n-1)/3+1<<endl;
		return;
	}
	int cnt=1;
	int lst=s[pos];
	for (int p=pos+1;p!=pos;p=(p+1)%n)
	{
		if (lst!=s[p])
			cnt=1;
		else
			cnt++;
		lst=s[p];
		//WRT(cnt);
		if (cnt==3)
		{
			cnt=0;
			ans++;
		}
	}
	cout<<ans<<endl;
	
}
int main()
{
	int t;
	cin>>t;
	while (t--)
		work();
	return ~~(0^_^0);
}