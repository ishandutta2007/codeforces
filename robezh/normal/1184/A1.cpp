#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
const int oo = (int) 9e18;
int r;
bool check(int x,int b)
{
	// x+2y+1 = b <=> y = (b-1-x)/2
	if (abs(b-1-x)%2!=0)
		return false;
	int y=(b-1-x)/2;
	if (x>0 and y>0)
	{
		//cout << x << ' ' << y << '\n';
		return true;
	}
	else
		return false;
}
main()
{
	ios_base::sync_with_stdio(0);
	//("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> r;
	r--;
	int res=oo;
	for (int i=1; i*i<=r; i++)
		if (r%i==0)
		{
			if (check(i,r/i))
			{
				res=min(res,i);
			}
			if (check(r/i,i))
			{
				res=min(res,i);
			}
		}
	
	if (res==oo)
		cout << "NO";
	else
	{
		cout << res << ' ' << (r/res-1-res)/2;
	}
	return 0;
}