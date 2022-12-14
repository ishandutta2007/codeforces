# include <iostream>
# include <algorithm>
using namespace std;
char a[100];
char b[100];
int main ()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	for (int i=0;i<n;i++)
		cin>>b[i];
sort(a,a+n);
sort(b,b+n);
bool a1=1,a2=1;
	for (int i=0;i<n;i++)
	{
		if (a[i]>=b[i])
		{
			a1=0;
			break;
		}
	}
	for (int i=0;i<n;i++)
	{
		if (a[i]<=b[i])
		{
			a2=0;
			break;
		}
	
	}
	if (a1==1 || a2==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}