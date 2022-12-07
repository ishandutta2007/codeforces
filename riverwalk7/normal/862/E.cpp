#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#define MAXN 100100
using namespace std;
typedef long long ll;
int N, M, Q;
ll a[MAXN], b[MAXN];
ll K, y[MAXN];
int l, r; ll x;
void solve()
{
    int lbound = 0; int hbound = M-N; int avg;
    while(lbound != hbound)
    {
        avg = (lbound + hbound)/2;
        if(y[avg] >= K)
        {
            hbound = avg;
        }
        else
        {
            lbound = avg + 1;
        }
    }
    if(hbound >= 1 && K <= y[M-N])
    {
        cout<<min(y[hbound]-K, K-y[hbound-1])<<endl;
    }
    else
    {
        cout<<abs(y[hbound]-K)<<endl;
    }
}
int main()
{
    cin>>N>>M>>Q;
    for(int i=1; i<=N; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=M; i++)
    {
        cin>>b[i];
    }
    for(int i=1; i<=N; i++)
    {
        if(i%2==0)
        {
            K += a[i];
            y[0] += b[i];
        }
        else
        {
            K -= a[i];
            y[0] -= b[i];
        }
    }
    for(int i=1; i<=(M-N); i++)
    {
        y[i] = -y[i-1] - b[i];
        if(N%2==0)
        {
            y[i] += b[i+N];
        }
        else
        {
            y[i] -= b[i+N];
        }
    }
    sort(y, y+M-N+1);
    solve();
    for(int i=0; i<Q; i++)
    {
        cin>>l>>r>>x;
        if(l%2==r%2)
        {
            if(r%2==0)
            {
                K += x;
            }
            else
            {
                K -= x;
            }
        }
        solve();
    }
}