#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cin>>a>>b>>c>>d;
	cout<<(((a ^ b) & (c | d)) ^ ((b & c) | (a ^ d)))<<endl;
	return 0;
}