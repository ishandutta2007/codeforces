#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 100010

int n,m;
int a[N],b[N];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i ++) scanf("%d",a+i);
    for (int i = 0; i < m; i ++) scanf("%d",b+i);
    ll SA = 0, SB = 0;
    for (int i = 0; i < n; i ++) SA += a[i];
    for (int i = 0; i < m; i ++) SB += b[i];
    sort(a,a+n);
    sort(b,b+m);
    ll SSA = SB, SSB = SA;
    for (int i = 0; i < n-1; i ++) SSA += min(SB,(ll)a[i]);
    for (int i = 0; i < m-1; i ++) SSB += min(SA,(ll)b[i]);
    cout << min(SSA,SSB) << endl;
    return 0;
}