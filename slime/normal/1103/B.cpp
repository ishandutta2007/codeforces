#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
#define mod 998244353
using namespace std;
ll l, r;
int ask(int x, int y)
{
	cout<<"? "<<x<<" "<<y<<endl;
	fflush(stdout);	
	char xs[3];
	scanf("%s", xs);
	if(xs[0] == 'x') return 0;
	else return 1; 
}
bool check()
{
	if(ask(1, 2)) return 0;
	if(ask(4, 3) == 0) return 1;
	else return 0;
}
void otp(int x)
{
	cout<<"! "<<x<<endl;
	fflush(stdout);
}
int main()
{
	while(1)
	{
		char inp[10];
		scanf("%s", inp);
		if(inp[0] == 'e') return 0;
		if(check()) otp(1);
		else
		{
			l = 1;
			while(ask(l, (l << 1)) == 1) l <<= 1;
			int s = l;
			r = (l << 1);
			l++;
			while(l < r)
			{
				int mid = (l + r) >> 1;
				if(ask(s, mid) == 1)
					l = mid + 1;
				else r = mid;
			}
			otp(l);
		}
	}
	return 0;
}