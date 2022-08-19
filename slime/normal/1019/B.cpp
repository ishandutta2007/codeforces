#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define ll long long
#define maxn 3005
using namespace std;	
int n;
int ask(int t)
{
	cout<<"? "<<t<<" "<<endl;
	fflush(stdout);
	int x, y;
	cin>>x;
	cout<<"? "<<t + n / 2<<" "<<endl;
	fflush(stdout);
	cin>>y;
	return y - x;
}
int main()
{

	scanf("%d", &n);
	if(n % 4)
	{
		cout<<"! -1"<<endl;
		fflush(stdout);
		return 0;
	}
	else
	{
		int a = ask(1);
		if(a == 0)
		{
			cout<<"! 1"<<endl;
			fflush(stdout);
			return 0;
		}
		int l = 1, r = n / 2 + 1, ltp = 0, rtp = 0;
		if(a < 0) rtp = 1;
		else ltp = 1;
		while(l < r)
		{
			int mid = (l + r) >> 1;
			int b = ask(mid + 1);
			if(b == 0)
			{
				cout<<"! "<<mid + 1<<endl;
				fflush(stdout);
				return 0;
			}
			int ntp = 0;
			if(b > 0) ntp = 1;
			if(ntp == ltp) l = mid + 1;
			else r = mid;
		}
	}
	return 0;
}