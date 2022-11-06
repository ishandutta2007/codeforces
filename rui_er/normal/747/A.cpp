#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int a=sqrt(n);a>=0;a--)
		for(int b=sqrt(n);b<=n;b++)
			if(a * b == n)
			{
				cout<<a<<" "<<b<<endl;
				return 0;
			}
	return 0;
}