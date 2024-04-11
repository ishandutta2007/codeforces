#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define mod 998244353
#define maxn 500005
#define ll long long
#define ld long double
using namespace std;
struct pt
{
	ld x, y;
}A[2][20], x1, x2;
int cnt[2];
ld ans;
ld cal1(pt x, pt y)
{
	return abs(x.x - y.x) + abs(x.y - y.y);
}
ld sqr(ld a)
{
	return a * a;
}
ld cal2(pt x, pt y)
{
	return sqrt(sqr(x.x - y.x) + sqr(x.y - y.y));
}
void cal(pt x, pt y)
{
	ld nans = cal1(x1, x) + cal1(x2, y) + cal2(x, y);
//	cout<<nans<<" "<<ans<<endl;
	ans = min(ans, nans);
}
ll a, b, c;
void otp()
{
	printf("%.10lf\n",(double)ans); 
}
void push(pt x, int id)
{	
	pt n1;
	n1.x = x.x, n1.y = 1.0 * (-c - a * x.x) / b;
	A[id][cnt[id]++] = n1;
	pt n2;
	n2.y = x.y, n2.x = 1.0 * (-c - b * x.y) / a;
	A[id][cnt[id]++] = n2;
}
int main()
{
	scanf("%lld%lld%lld", &a, &b, &c);
	ll x[2], y[2];
	scanf("%lld%lld%lld%lld", &x[0], &y[0], &x[1], &y[1]);
	x1.x = x[0], x1.y = y[0], 
	x2.x = x[1], x2.y = y[1];
	ans = cal1(x1, x2);
//	cout<<ans<<endl;
	if(a == 0 || b == 0)
	{
		otp();
		return 0;
	}
	push(x1, 0), push(x2, 1);
	for(int i = 0; i < cnt[0]; i++)
		for(int j = 0; j < cnt[1]; j++)
			cal(A[0][i], A[1][j]);
	otp();
	return 0;
}