#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define vt vector<int>
#define maxn 300005
#define ll long long
#define ld double
using namespace std;
int n;
ll a[maxn];
ll sum[maxn];
int main()
{
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]), 
		sum[i] = sum[i - 1] + a[i];
	ll ns = 0, lt = 0;
	for(int i = n; i >= 1; i--)
	{
		ll mst = (sum[i] - lt) / 3;
		mst = min(mst, a[i] / 2);
		ns += mst, lt += mst;
		a[i] -= mst * 2;
		lt -= a[i];
		lt = max(lt, (ll)0);
	}
	cout<<ns<<endl;
	return 0;
} 
/*5 100
4 1 2 3 5
3
1 2 3 6
1 1 5 1
3 2 4
*/