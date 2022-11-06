#include <iostream>
using namespace std;

int f(int a, int b)
{
	if(a > b) return 0;
	else return 1 + f(3*a, 2*b);
}

int main()
{
	int a, b;
	cin>>a>>b;
	cout<<f(a, b)<<endl;
	return 0;
}