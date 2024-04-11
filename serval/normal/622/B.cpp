#include <iostream>
using namespace std;
int main()
{
	char x;
	int h,m,t;
	cin>>x;
	h=x-'0';
	cin>>x;
	h*=10;
	h+=x-'0';
	cin>>x;
	cin>>x;
	m=x-'0';
	cin>>x;
	m*=10;
	m+=x-'0';
	cin>>t;
	m+=t;
	h+=m/60;
	m%=60;
	h=h%24;
	cout<<h/10<<h%10<<':'<<m/10<<m%10;
	return 0;
}