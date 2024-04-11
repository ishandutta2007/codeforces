#include<iostream>
using namespace std;
int main()
{
	long long m,n;
	cin>>n>>m;
	if(n%2==0||m%2==0)
	cout<<(m*n)/2;
	else
	cout<<((m*n)-1)/2;
}