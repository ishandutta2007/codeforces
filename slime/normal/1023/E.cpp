#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define mod 998244353
#define maxn 2005
#define ll long long
using namespace std;
int n;
int cnt = 0;
char otp[maxn];
bool ask(int a, int b, int tp)
{
	if(a > n || b > n || a < 1 || b < 1) return 0;
	if(tp == 0) 
	{
		cout<<"? "<<1<<" "<<1<<" "<<a<<" "<<b<<endl;
		fflush(stdout);
	}
	else
	{
		cout<<"? "<<a<<" "<<b<<" "<<n<<" "<<n<<endl;
		fflush(stdout);
	}
	char inp[4];
	scanf("%s", inp);
	if(inp[0] == 'Y') return 1;
	return 0;
}
int main()
{
	scanf("%d", &n);
	int x = n, y = n;
	while(x + y > n + 1)
	{
		if(ask(x - 1, y, 0))
			otp[x + y - 3] = 'D', x--;
		else
			otp[x + y - 3] = 'R', y--;
	}
	x = 1, y = 1;
	while(x + y < n + 1)
	{
		if(ask(x, y + 1, 1))
			otp[x + y - 2] = 'R', y++;
		else
			otp[x + y - 2] = 'D', x++;
	}
	cout<<"! ";
	for(int i = 0; i < 2 * n - 2; i++)
		cout<<otp[i];
	cout<<endl;
	fflush(stdout);
	return 0;
}