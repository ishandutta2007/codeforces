#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXN 300300
using namespace std;
typedef long long ll;
struct plane
{
    ll x, y, z;
    plane()
    {
        x = y = z = 0;
    }
    bool operator <(const plane &rhs) const
    {
        return x > rhs.x;
    }
};
int K, N;
plane c[MAXN];
bool occupied[MAXN*2];
ll ans;
ll g; int h;
bool comp(plane a, plane b)
{
    return a.y < b.y;
}
int main()
{
    cin>>N>>K;
    for(int i=0; i<N; i++)
    {
        cin>>c[i].x;
        c[i].y = i+1;
    }
    sort(c, c+N);
    g = K+1;
    for(int i=0; i<N; i++)
    {
        h = c[i].y;
        if(c[i].y < g)
        {
            h = g;
            while(occupied[g])
            {
                ++g;
                ++h;
            }
        }
        occupied[h] = true;
        c[i].z = h;
        ans += (c[i].x * (h - c[i].y));
        while(occupied[g])
        {
            g++;
        }

        occupied[h] = true;
    }
    sort(c, c+N, comp);
    cout<<ans<<endl;
    for(int i=0; i<N-1; i++)
    {
        cout<<c[i].z<<" ";
    }
    cout<<c[N-1].z<<endl;
}