#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
#define mod 1000000007
using namespace std;
struct pt
{
	ll x, y;
	bool operator < (const pt &a)const
	{
		if(x == a.x) return y < a.y;
		return x < a.x;
	}
}p[maxn];
pt st[maxn];
int top = 0;
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld%lld", &p[i].x, &p[i].y);
		p[i].y -= p[i].x * p[i].x;
	}
	sort(p + 1, p + n + 1);
	for(int i = 1; i <= n; i++)
	{
		while(top >= 2 && 
		(st[top - 1].x - st[top - 2].x) * (p[i].y - st[top - 1].y) >=  
		(st[top - 1].y - st[top - 2].y) * (p[i].x - st[top - 1].x) )
			top--;
		st[top++] = p[i];
	}
//	cout<<top<<endl;
	int ans = 0;
	for(int i = 0; i < top - 1; i++)
		if(st[i].x != st[i + 1].x) ans++;
	cout<<ans<<endl;	
//	for(int i = 0; i < top; i++)
//		cout<<st[i].x<<" "<<st[i].y<<endl;
//	cout<<top - 1<<endl;
	return 0;
}