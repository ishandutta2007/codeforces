#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin>>n>>m;
	int k = 0;
	while(n > 0)
	{
		k++;
		n--;
		if(k % m == 0) n++;
	}
	cout<<k<<endl;
	return 0;
}