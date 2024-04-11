#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
#define mod 1000000007
using namespace std;
int a[maxn], b[maxn];
int c[maxn];
int pl[maxn], tp[maxn];
int cnt = 0;
void push(int p, int t)
{
	if(cnt >= 100000) return;
	pl[cnt] = p, tp[cnt++] = t; 
} 
int sgn(int a)
{
	if(a > 0) return 1;
	return -1;
}
bool check(int a)
{
	return a >= 0 && a <= 9;
}
char inp[maxn];
int main()
{
	int n;
	cin>>n;
	scanf("%s", inp);
	for(int i = 1; i <= n; i++)
		a[i] = inp[i - 1] - '0';
	scanf("%s", inp);
	for(int i = 1; i <= n; i++)
		b[i] = inp[i - 1] - '0';
	ll ans = 0;
	for(int i = 1; i <= n; i++)
		c[i] = (b[i] - (a[i] + c[i - 1])), 
		ans += abs(c[i]);
	//cout<<c[1]<<" "<<c[2]
	if(c[n]) cout<<-1<<endl;
	else
	{
		int i = 1;
		while(i <= n)
		{
			if(cnt == 100000) break;
			if(c[i] == 0) 
			{
				i++;
				continue;
			}
			int pl = 0;
			for(int j = i; j <= n; j++)
				if(check(a[j] + sgn(c[j])) && check(a[j + 1] + sgn(c[j])))
				{
					pl = j;
					break;
				}
			for(int s = pl; s >= i; s--)
				push(s, sgn(c[s])),
				a[s] += sgn(c[s]), 
				a[s + 1] += sgn(c[s]), 
				c[s] -= sgn(c[s]);
		//	cout<<pl<<" "<<c[i]<<endl;
		}
		cout<<ans<<endl;
		for(int i = 0; i < cnt; i++)
			cout<<pl[i]<<" "<<tp[i]<<endl;
	}
	return 0;
}