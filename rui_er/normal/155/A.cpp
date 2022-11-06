#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a;
	int max = -2147483648;
	int min = 2147483647;
	int count = 0;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a > max)
		{
			max = a;
			if(i != 0) count++;
		}
		if(a < min)
		{
			min = a;
			if(i != 0) count++;
		}
	}
	cout<<count<<endl;
	return 0;
}