# include <iostream>
# include <string>
# include <algorithm>
using namespace std;
long long a[10000000];
int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	long long int ans=0;
	for (int i=0;i<n;i++)
		ans+=abs(a[i]-(i+1));
	cout<<ans<<endl;
}