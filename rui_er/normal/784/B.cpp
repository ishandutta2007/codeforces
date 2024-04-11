#include <iostream>
using namespace std;

int main()
{
	int n, cnt = 0, x;
	cin>>n;
	if(n == 0)
	{
		cout<<1<<endl;
		return 0;
	}
	while(n)
	{
		x = n % 16;
		n /= 16;
		if(x == 0 || x == 4 || x == 6 || x == 9 || x == 10 || x == 13) ++cnt;
		if(x == 8 || x == 11) cnt += 2;
	}
	cout<<cnt<<endl;
	return 0;
}