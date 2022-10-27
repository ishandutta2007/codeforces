#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
const int NICO = 1000000 + 10;
int a[NICO];
int n, k;
int count(int x, int y)//yx
{
    if(x > y) return 0;
    int res = 1;
    int rank = 1;  
    int tmp = y;                
    y >>= 1;
    while(y+1 >= x)
    {
        if(y >= x) res <<= 1;
        if(x == y+1)
        {
            res = max(tmp - (1 << rank)*y, res); 
            break;
        }
        y >>= 1, rank ++;
    }
    return res;
}
bool judge(int x)
{
    ll cnt = 0;
    for(int i=1;i<=n;i++)
    {
        cnt += count(x, a[i]);
    }
    if(cnt >= k) return 1;
    return 0;
}
void solve()
{
    int l = 1, r = 1e7, mid;
    while(r > l + 1)
    {
        mid = (r + l) / 2;
        if(judge(mid))
        {
            l = mid;
        } else {
            r = mid-1;
        }
    }
    if(judge(r)) mid = r;
    else mid = l;
    if(!judge(1)) cout << -1 << endl;
    else cout << mid << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    solve();
}