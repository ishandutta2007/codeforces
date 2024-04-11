#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#define maxn 200005
#define ll long long
#define mod 1000000007
using namespace std;
ll l, r;
int read()
{
	char inp[10];
	scanf("%s", inp);
	if(inp[0] == 'Y') return 1;
	return 0;
}
int main()
{
	srand(time(0));
	ll n;
	int k;
	scanf("%lld%d", &n, &k);
	l = 1, r = n;
	for(int i = 1; i <= 4500; i++)
	{
		if((r - l) >= 50)
		{
			ll mid = (r + l) >> 1;
			cout<<l<<" "<<mid<<endl;
			fflush(stdout);
			if(read()) r = mid;
			else l = mid + 1;
		}
		else
		{
			ll pl = rand() % (r - l + 1) + l;
			cout<<pl<<" "<<pl<<endl;
			fflush(stdout);
			if(read())
				return 0;
		}
		l -= 10, r += 10;
		if(l <= 0) l = 1;
		if(r > n) r = n;
	}
	return 0;
}