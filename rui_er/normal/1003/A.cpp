#include <iostream>
#include <limits.h>
using namespace std;

int cnt[1000001];

int main()
{
	int n;
	int k;
	int m = INT_MIN;
	cin>>n;
	while(n--)
	{
		cin>>k;
		cnt[k]++;
		m = max(m, cnt[k]);
	}
	cout<<m<<endl;
	return 0;
}