#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		if(i % 2 == 0) cout<<"I hate that ";
		else cout<<"I love that ";
	}
	if((n - 1) % 2 == 0) cout<<"I hate it"<<endl;
	else cout<<"I love it"<<endl;
	return 0;
}