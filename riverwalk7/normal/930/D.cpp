#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXN 100100
using namespace std;
typedef long long ll;
struct token
{
    ll x, y;
    token()
    {
        x = y = 0;
    }
    bool operator <(const token &rhs) const
    {
        return x < rhs.x;
    }
};
bool comp(token a, token b)
{
    return a.y < b.y;
}
typedef long long ll;
int N;
int a, b;
token c[MAXN];
ll ans;
ll l[5*MAXN], r[5*MAXN], l2[5*MAXN], r2[5*MAXN]; int counter;
ll u, v, u2, v2, cc, dd;
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a>>b;
        c[i].x = a+b; c[i].y = a-b;
        c[i].x += 200000;
        c[i].y += 200000;
        if(c[i].x%2==0)
        {
            ++cc;
        }
        else
        {
            ++dd;
        }
        //cout<<c[i].x<<" "<<c[i].y<<endl;
    }
    sort(c, c+N);
    for(int i=0; i<5*MAXN; i++)
    {
        l[i] = l2[i] = 410000; r[i] = r2[i] = -410000;
    }
    u = 410000; v = -410000; u2 = 410000; v2 = -410000;
    for(int i=0; i<=400000; i++)
    {
        if(i%2==1)
        {
            l[i] = min(l[i], u);
            r[i] = max(r[i], v);
        }
        else
        {
            l[i] = min(l[i], u2);
            r[i] = max(r[i], v2);
        }
        if(i%2==0)
        {
            while(counter != N&&c[counter].x == i)
            {
                u = min(u, c[counter].y+1);
                v = max(v, c[counter].y-1);
                ++counter;
            }
        }
        else
        {
            while(counter != N&&c[counter].x == i)
            {
                u2 = min(u2, c[counter].y+1);
                v2 = max(v2, c[counter].y-1);
                ++counter;
            }
        }
    }
    counter = N-1;
    u = 410000; v = -410000; u2 = 410000; v2 = -410000;
    for(int i=400000; i>=0; i--)
    {
        if(i%2==1)
        {
            l2[i] = min(l2[i], u);
            r2[i] = max(r2[i], v);
        }
        else
        {
            l2[i] = min(l2[i], u2);
            r2[i] = max(r2[i], v2);
        }
        if(i%2==0)
        {
            while(counter != -1&&c[counter].x == i)
            {
                u = min(u, c[counter].y+1);
                v = max(v, c[counter].y-1);
                --counter;
            }
        }
        else
        {
            while(counter != -1&&c[counter].x == i)
            {
                u2 = min(u2, c[counter].y+1);
                v2 = max(v2, c[counter].y-1);
                --counter;
            }
        }
    }
    for(int i=0; i<=400000; i++)
    {
        l[i] = max(l[i], l2[i]);
        r[i] = min(r[i], r2[i]);
        if(l[i] <= r[i])
        {
            if(i%2==1)
            {
                l[i]--; r[i]--;
            }
            if(i%2==1&&cc>=4)
            ans += (r[i]/2-(l[i]-1)/2);
            if(i%2==0&&dd>=4)
                ans += (r[i]/2-(l[i]-1)/2);
        }
    }
    cout<<ans<<endl;
}