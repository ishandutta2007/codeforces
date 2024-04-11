#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() 
{
	int t;
	cin>>t;
	while(t--) 
    {
		int n;
		cin>>n;
		int res=0;
		while(n) 
        {
			res+=n;
			n/=2;
		}
		cout<<res<<'\n';
	}
	return 0;
}