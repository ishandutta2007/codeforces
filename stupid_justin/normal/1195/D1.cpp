#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,ans,a;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) 
	{
		cin>>a;
//		a%=MOD;
		long long s=11ll*n;
		while(a!=0ll)
		{
			
			long long tmp=((a%10ll)*s)%MOD;
			ans=(ans+tmp)%MOD;
			a/=10ll;
			s=(s*100ll)%MOD;
//			cout<<s<<" "<<a<<" "<<tmp<<" "<<ans<<endl;
		}
//		cout<<ans<<endl;
	}
//	cout<<ans<<endl;
	cout<<ans%MOD<<endl;
}