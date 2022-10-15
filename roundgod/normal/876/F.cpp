#include<bits/stdc++.h>
#define MAXN 200020
using namespace std;
typedef long long ll;
ll n;
ll h[MAXN];
ll L[MAXN],R[MAXN];
ll st[MAXN];
void solve()
{
	ll t=0;
	for(ll i=0;i<n;i++)
	{
		while(t>0&&((h[st[t-1]]|h[i])==h[i])&&h[i]!=h[st[t-1]]) t--;
		L[i]=t==0?-1:(st[t-1]);
		st[t++]=i;
	}
	t=0;
	for(ll i=n-1;i>=0;i--)
	{
		while(t>0&&((h[st[t-1]]|h[i])==h[i])) t--;
		R[i]=t==0?n:st[t-1];
		st[t++]=i;
	}
	ll res=n*(n+1)/2;
	for(ll i=0;i<n;i++)
        res-=(i-L[i])*(R[i]-i);
	printf("%I64d\n",res);
}
int main()
{
    scanf("%I64d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d",&h[i]);
    solve();
    return 0;
}