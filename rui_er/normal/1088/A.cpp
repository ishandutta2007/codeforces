#include <iostream>
using namespace std;

int main()
{
	int x;
	cin>>x;
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=x;j++)
		{
			if(i * j > x && i / double(j) < double(x) && i % j == 0)
			{
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
	cout<<"-1"<<endl;
	return 0;
}