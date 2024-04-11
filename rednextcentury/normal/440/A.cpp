# include <iostream>
# include <string>
using namespace std;
int main()
{
	long long sum=0;
	long long n;
	cin>>n;
	long long j;
	for (int i=0;i<n-1;i++)
	{
		cin>>j;
		sum+=j;
	}
	cout<<n*(n+1)/2-sum<<endl;
}