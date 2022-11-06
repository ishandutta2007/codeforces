#include <iostream>
using namespace std;

#define LL long long

int main()
{
	LL k, l;
	cin>>k>>l;
	//l = k^n
	LL n = 1;
	for(LL i=0;n<=l;i++)
	{
		if(n == l)
		{
			cout<<"YES"<<endl<<(i-1)<<endl;
			return 0;
		}
		n *= k;
	}
	cout<<"NO"<<endl; 
	return 0;
}