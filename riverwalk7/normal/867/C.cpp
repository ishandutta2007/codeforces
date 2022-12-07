#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXN 100100
using namespace std;
typedef long long ll;
struct person
{
    ll s, a, b;
    person()
    {
        s = a = b = 0;
    }
    bool operator <(const person &rhs) const
    {
        return (a-b) < (rhs.a-rhs.b);
    }
};
int N; ll S;
person x[MAXN];
ll y[MAXN];
ll sum;
ll m, n, ans;
ll solve(ll u, ll v)
{
    ll c = u*S;
    ll d = v*S;
    ll cur = 0;
    ll p;
    for(int i=0; i<N; i++)
    {
        x[i].s = y[i];
    }
    for(int i=0; i<N; i++)
    {
        if((x[i].b-x[i].a) > 0)
        {
            p = min(d, x[i].s);
            cur += (x[i].b * p);
            d -= p;
            x[i].s -= p;
        }
    }
    for(int i=N-1; i>=0; i--)
    {
        if((x[i].a-x[i].b) > 0)
        {
            p = min(c, x[i].s);
            cur += (x[i].a * p);
            c -= p;
            x[i].s -= p;
        }
    }
    for(int i=0; i<N; i++)
    {
        if(x[i].s > 0)
        {
            if(c > 0)
            {
                c -= x[i].s;
                cur += (x[i].s * x[i].a);
            }
            else
            {
                d -= x[i].s;
                cur += (x[i].s * x[i].b);
            }
        }
    }
    return cur;
}
int main()
{
    cin>>N>>S;
    for(int i=0; i<N; i++)
    {
        cin>>x[i].s>>x[i].a>>x[i].b;
        sum += x[i].s;
    }
    sum = (sum+S-1)/S;
    sort(x, x+N);
    for(int i=0; i<N; i++)
    {
        y[i] = x[i].s;
        if((x[i].a-x[i].b) < 0)
        {
            n += x[i].s;
            ans += (x[i].s * x[i].b);
        }
        else
        {
            m += x[i].s;
            ans += (x[i].s * x[i].a);
        }
    }
    if(((m+S-1)/S+(n+S-1)/S) == sum)
    {
        cout<<ans<<endl;
        return 0;
    }
    else
    {
        cout<<max(solve((m-1)/S, (n+S-1)/S), solve((m+S-1)/S, (n-1)/S))<<endl;
    }
}