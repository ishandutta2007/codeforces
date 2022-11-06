#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
	int MAX, CUR;
	MAX = INT_MIN;
	int n;
	cin>>n;
	int a[n];
	cin>>a[0];
	CUR = 1;
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
		if(a[i] >= a[i-1]) CUR++;
		else
		{
			MAX = max(MAX, CUR);
			CUR = 1;
		}
	}
	MAX = max(MAX, CUR);
	cout<<MAX<<endl;
	return 0;
}