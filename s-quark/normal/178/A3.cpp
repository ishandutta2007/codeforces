#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)
const int MAXN = 100004;

int a[MAXN];

int main()
{
	#ifdef __FIO
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	int n;
	ll ans = 0;
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	j = 1;
	while((1<<j) < n)
		j++;
	j--;
	for(i = 0; i < n-1; i++){
		while(i+(1<<j) >= n)
			j--;
		ans += a[i];
		a[i+(1<<j)] += a[i];
		cout<<ans<<endl;
	}
	return 0;
}