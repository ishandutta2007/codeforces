#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin>>n>>k;
	int time = 4 * 60;
	time -= k;
	for(int i=1;i<=n;i++)
	{
		if(time >= i * 5) time -= i * 5;
		else
		{
			cout<<i-1<<endl;
			return 0;
		}
	}
	if(time >= 0) cout<<n<<endl;
	return 0;
}