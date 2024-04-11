#include<bits/stdc++.h>
using namespace std;
int n,k,T;
long long f[233];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		memset(f,0,sizeof(f));
		f[0]=f[1]=2;
		for(int i=2;i<=30;i++)
		{
			f[i]=((1ll<<(i-1))+1)*f[i-1]%k;
//			cerr<<i<<' '<<f[i]<<' ';
		}
		long long l=1,t=0,s=0;
		while(l<n)
		{
			s+=(f[t]*(l+1)/2)%k;
			l=l*2+1;
			t++;
		}
		l/=2;
		s+=f[t]*(n-l);
		cout<<(s-1+k)%k<<endl;
	}
	return 0;
}