#include <iostream>
#include <iomanip> 
using namespace std;

int main()
{
	int a[32] = {0}, b[32] = {0};
	double n, cnt;
	cnt = 0.0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	for(int i=0;i<1000000;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i % a[j] == b[j])
			{
				++cnt;
				break;
			}
		}
	}
	cout<<fixed<<setprecision(6)<<(cnt/1000000.0)<<endl;
	return 0;
}