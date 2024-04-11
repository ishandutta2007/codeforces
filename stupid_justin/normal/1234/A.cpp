#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int n,tot;
int a[N];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		tot=0;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
			tot+=a[i];
		}
		cout<<(tot+n-1)/n<<endl;
	} 
		
}