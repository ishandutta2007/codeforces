#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
ll n, l, r;
ll max(ll x, ll y){return x<y?y:x;}
ll c(double x)
{
    return (ll)(x+1-EPS);
}
ll gcd(ll x, ll y)
{
    if(y == 0) return x;
    return gcd(y, x%y);
}
ll pow1(ll a, ll n)
{
    ll ret = 1;
    while(n)
    {
        if(n & 1)
        {
            ret = (ret * a);
            if(ret / 1000.0 * a / 1000.0 > 1e12) return -1;
        }
        a = a * a;
        if(n != 1 && a > 1e9) return -1;
        n >>= 1;
    }
    return ret;
}
int main()
{
    cin >> n >> l >> r;
    ll res = 0;
    if(n == 1)
    {
        res = r - l + 1;   
    }
    if(n == 2)
    {
        res = (r - l + 1) * (r - l);
    }
    if(n >= 3)
    {
        ll p_, q_;
        for(ll q = 1; ; q++)
        {
            q_ = pow1(q, n-1);
            if(q_ == -1) break;
            for(ll p = q + 1; ; p++)
            {
                ll tmp = gcd(p, q);
                if(tmp != 1) continue;
                p_ = pow1(p, n-1);
                if(p_ == -1) break;
                res += max(r/p_ - c(1.0*l/q_) + 1, 0);
                if(p_ > r) break;
            }
            if(q_ > r) break;
        }
        res *= 2;
    }
    cout << res << endl;
}