# include <iostream>
# include <string>
# include <algorithm>
using namespace std;
int a[100001];
int main()
{
	int n;
	cin>>n ;
	for (int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	cout<<a[n-1]<<" ";
	for (int i=1;i<n-1;i++)
		cout<<a[i]<<" ";
	cout<<a[0]<<endl;
}