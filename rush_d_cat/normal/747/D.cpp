#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int NICO = 200000 + 10;
int n, k, cnt, res;
int a[NICO], b[NICO];
int main()
{
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        int x; cin >> x;
        if(x < 0) a[++cnt] = i; 
    }
    if(cnt > k) {printf("-1\n");return 0;}
    if(cnt == 0){printf("0\n");return 0;}
    k -= cnt; res = 2 * cnt;
    for(int i=1;i<cnt;i++)
    {
        b[i] = a[i+1]-a[i]-1;    
    }
    sort(b+1, b+cnt);
    for(int i=1;i<cnt;i++)
    {
        if(b[i] <= k) k -= b[i], res -= 2;
    }
    if(n - a[cnt] <= k) res --;
    cout << res << endl;
}