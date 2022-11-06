#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int k = n % 10;
	if(k <= 4) cout<<10*(n/10)<<endl;
	else cout<<10*(n/10)+10<<endl;
	return 0;
}