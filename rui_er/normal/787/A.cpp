#include<iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cin>>a>>b>>c>>d;
	int k = -1;
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			if(i*a+b == j*c+d)
			{
				cout<<i*a+b<<endl;
				return 0;
			}
	cout<<-1<<endl;
	return 0;
}