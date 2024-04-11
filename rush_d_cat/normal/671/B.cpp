#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int NICO = 500000 + 10;
int n, k;
int c[NICO];
bool ok(int x)
{
    LL sum = 0;
    for(int i=1;i<=n;i++)
    {
        if(x < c[i]) break;
        sum += (x - c[i]);
    }
    if(sum <= k) return 1;
    return 0;
}
int main()
{
    cin >> n >> k;
    LL s = 0;
    for(int i=1;i<=n;i++)
    {
        cin >> c[i];
        s += c[i];
    }
    sort(c+1, c+1+n);
    int l = 1, r = 1e9;
    while(r-l>1)
    {
        int mid = (l+r)/2;
        if(ok(mid)) l = mid;
        else r = mid;
    }
    int ans1 = l;
    for(int i=1;i<=n;i++)
    {
        c[i] = 1e9+1-c[i];
    }
    sort(c+1,c+1+n);
    l = 1, r = 1e9;
    while(r-l>1)
    {
        int mid = (l+r)/2;
        if(ok(mid)) l = mid;
        else r = mid;
    }
    int ans2 = 1e9+1-l;
    if(ans2 > ans1) cout << (ans2-ans1) << endl;
    else cout << (s%n?1:0) << endl;
}