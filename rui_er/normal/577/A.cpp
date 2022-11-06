#include <iostream>
using namespace std;

int main()
{
	long long n, k;
	cin>>n>>k;
	long long cnt = 0;
	for(long long i=1;i<=n;i++)
		if(i * n >= k)
			if(k % i == 0)
				++cnt;
	cout<<cnt<<endl;
	return 0;
}