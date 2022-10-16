#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int p[11]={0,5,3,2,4,1};
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	reverse(p,p+6);
	int ans=0;
	for(int i=0;i<6;i++)
	{
		if(n&(1<<i))ans+=(1<<(5-p[i]));
	}
	cout<<ans<<endl;
	return 0;
}