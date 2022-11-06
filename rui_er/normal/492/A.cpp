#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int ans = 0;
	int a = 0;
	for(int i=1;;i++)
	{
		a += i;
		n -= a;
		if(n >= 0) ++ans;
		else break;
	}
	cout<<ans<<endl;
	return 0;
}//
//
//;;;;