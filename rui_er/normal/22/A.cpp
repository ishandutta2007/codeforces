#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int a;
bool f[500];

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		f[a+100] = true;
	}
	int cnt = 0;
	for(int i=-100;i<=100;i++)
	{
		if(f[i+100]) cnt++;
		if(cnt == 2)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}