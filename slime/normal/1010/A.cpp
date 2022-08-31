#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1005
#define mod 998244353
#define ld double
const ld eps = 0.000000001;
int n, m;
int a[maxn], b[maxn];
ld cal(ld a, ld b)
{
	if(a < 0) return a;
	return (a + m) - (a + m) / b - m;
}
bool check(ld t)
{
	t = cal(t, a[1]);
	for(int i = 2; i <= n; i++)
	{
		t = cal(t, b[i]);
		t = cal(t, a[i]);
	}
	t = cal(t, b[1]);
	if(t < 0) return 0;
	return 1;
}
int main()
{
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	for(int j = 1; j <= n; j++)
		cin>>b[j];
	if(!check(1e9+7)) 
	{
		cout<<-1<<endl;
		return 0;
	}
	ld l = 0, r = 1e9;
	int tms = 0;
	while(r - l > eps && tms < 1000)
	{
		tms++;
		ld mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid;
	}
    printf("%.10lf\n", l);
	return 0;	
}