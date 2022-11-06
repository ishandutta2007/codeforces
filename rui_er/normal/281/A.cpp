#include <iostream>
using namespace std;

int main()
{
	char c[10000];
	cin.getline(c, 10000);
	if(c[0] >= 'a') c[0] += 'A' - 'a';
	cout<<c<<endl;
	return 0;
}