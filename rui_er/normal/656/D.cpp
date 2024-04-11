#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	char c[128] = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";   // 
	int k = 0;
	while(int(pow(8, k++)) <= n);
	int cnt = 0;
	while(n)
	{
		if(n / int(pow(8, --k)) == 1) cnt++;
		n %= int(pow(8, k));
	} 
	cout<<cnt<<endl;
	return 0;
}