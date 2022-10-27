#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100005
#define MAXM 1000005
typedef __int64 ll;
ll max(ll a,ll b){return a<b?b:a;}
ll min(ll a,ll b){return a>b?b:a;}
int main()
{
	ll l1,l2,r1,r2,k;
	cin>>l1>>r1>>l2>>r2>>k;
	ll x,y,res;
	x = max(l1,l2);
	y = min(r1,r2);
	res = y-x+1;
	if(x<=k&&k<=y) res--;
	if(res<0) cout<<0;
	else cout<<res;
}