#include <iostream>
using namespace std;
typedef long long ll;
ll n, m, k;
ll f(int x, int len)
{
    if(len==0) return 0;
    if(x > len) return (ll)len*(2*x-len-1)/2;
    else return (ll)x*(x-1)/2 + len - x + 1; 
}
bool ok(int x)
{
    if(f(x, k-1) + f(x,n-k) + x <= m) return 1;
    else return 0;
}
int main()
{
    cin >> n >> m >> k;
    int l=1, r=1e9;
    while(r-l>1)
    {
        int mid = (l+r)/2;
        if(ok(mid))
        {
            l = mid;
        } else {
            r = mid;
        }
    }
    int res = 0;
    if(ok(l)) res = l;
    if(ok(r)) res = r;
    cout << res << endl;
}