#include<bits/stdc++.h>
using namespace std;
long long n,m,t,s1,s2,s;
long long a[200001];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    }
    if(n<=m)
    {
    	s=1;
    	for(int i=1;i<=n;i++)
    	{
    		for(int j=i+1;j<=n;j++)
    		{
    			s*=abs(a[i]-a[j])%m;
    			s%=m;
    		}
    	}
    	cout<<s<<endl;
    }
    else
    cout<<0<<endl;
}