#include <iostream>
using namespace std;

int k[4];

int main()
{
	int n;
	cin>>n;
	int a;
	while(n--)
	{
		cin>>a;
		++k[a];
	}
	if(k[1] >= max(k[2], k[3])) cout<<k[2]+k[3]<<endl;
	else if(k[2] >= max(k[1], k[3])) cout<<k[1]+k[3]<<endl;
	else cout<<k[1]+k[2]<<endl;
	return 0;
}