# include <iostream>
# include <string>
using namespace std;
int f[10000];
int main()
{
	int n,m;
	cin>>n>>m;
	for (int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		f[a-1]-=c;
		f[b-1]+=c;
	}
	long long ans=0;
	for (int i=0;i<n;i++)
	{
		if (f[i]>0)
		ans+=f[i];
	}
	cout<<ans<<endl;
}