#include <iostream>
using namespace std;

int main()
{
	int n, p, q;
	cin>>n>>p>>q;
	int cnt = 0;
	for(int i=1;i<=n;i++)
		if(i - 1 >= p && n - i <= q)
			++cnt;
	cout<<cnt<<endl;
	return 0;
}