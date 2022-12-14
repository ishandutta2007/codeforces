# include <iostream>
# include <algorithm>
using namespace std;
int a[10000];
int main()
{
	long long n,t,max=0;
	cin>>n;
	for (int i=0;i<n;i++)
	{
	cin>>t;
	if (t>max)
		max=t;
	a[t-1]++;
	}
	sort(a,a+max);
	if ((a[max-1]>n-a[max-1] && a[max-1]-(n-a[max-1])>1 ) && n!=1)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;





}