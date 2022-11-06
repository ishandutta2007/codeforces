#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	int cnt = 0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i] == 0) continue;
		bool flag = true;
		for(int j=0;j<i;j++)
		{
			if(a[i] == a[j])
			{
				flag = false;
				break;
			}
		}
		if(flag) ++cnt;
	}
	cout<<cnt<<endl;
	return 0;
}