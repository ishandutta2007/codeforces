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

int n;
char s[MAXN]; 
stack<int> st1,st2;
int main()
{
	cin>>n>>s;
	int t=0;
	int ans=0;
	for (int i=0;i<n;i++)
	{
		t+=(s[i]=='(' ? 1:-1);
		if (s[i]==')' && t<0 || s[i]=='(' && t<=0)
			ans++;
	}
	if (t!=0)
	{
		cout<<-1;
		return 0;
	}
	cout<<ans;
	return ~~(0^_^0);
}