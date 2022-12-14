# include <iostream>
# include <algorithm>
using namespace std;
int a[10000];
int main()
{
int n,k,g;
cin>>n>>k;
for (int i=0;i<n;i++)
	cin>>a[i];
sort (a,a+n);
if (n==k)
	cout<<0<<" "<<0<<endl;
else
{
int c=0;
for (int i=n-1;i>=0;i--)
{
	if (c==k)
	{
		cout<<a[i]+1<<" "<<a[i]+1<<endl;
		break;
	}

	c++;
}
if (c==n)
	cout<<-1<<endl;




}
}