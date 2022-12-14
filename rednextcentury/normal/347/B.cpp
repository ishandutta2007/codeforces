# include <iostream>
# include <string>
# include <map>
using namespace std;
int a[100001];
int main()
{
	map <int,int> m;
		int n;
		cin>>n;
		long long ans=0;
		for (int i=0;i<n;i++)
		{
			cin>>a[i];
			m[a[i]]=i;
			if (a[i]==i)
			{
				ans++;
			}
		}
		bool p=0;
		bool k=0;
		for (int i=0;i<n;i++)
		{
			if (a[i]!=i && a[i]==m[i] && a[a[i]]==i)
			{
				ans+=2;
				k=1;
				break;
			}
		}
		if (k==0)
		{
			if (ans<n)
				ans++;
		}
		cout<<ans<<endl;
}