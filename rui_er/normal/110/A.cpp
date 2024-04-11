#include <iostream>
using namespace std;

int main()
{
	int k = 0;
	long long n;
	cin>>n;
	while(n)
	{
		if(n % 10 == 4 || n % 10 == 7) ++k;
		n /= 10;
	}
	if(not k)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	bool flag = true;
	while(k and flag)
		if(k % 10 != 4 && k % 10 != 7)
			flag = false;
		else k /= 10;
	cout<<(flag ? "YES" : "NO")<<endl;
	return 0;
}