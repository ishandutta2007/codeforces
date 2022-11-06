#include<iostream>
using namespace std;

int main()
{
	char c[8];
	int sum = 0;
	cin>>c;
	for(int i=0;i<7;i++)
		sum += (c[i] == '1' ? 10 : (c[i] == 'A' ? 1 : (c[i] - '0')));
	cout<<sum<<endl;
	return 0;
}