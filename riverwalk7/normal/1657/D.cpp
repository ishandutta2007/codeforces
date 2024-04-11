#include <iostream>
#include <fstream>
#define MAXN 300300
#define MAXC 1000100
using namespace std;
typedef long long ll;
ll INF = 1e18+7;
int C, N, M;
ll best[MAXC];
ll best2[MAXC];
ll b[MAXN];
ll c, d, h;
ll D, H;
int solve(ll monster_strength)
{
    if(monster_strength >= best[C])
    {
        return -1;
    }
    int lbound = 1; int hbound = C; int avg;
    while(lbound != hbound)
    {
        avg = (lbound + hbound)/2;
        if(monster_strength >= best[avg])
        {
            lbound = avg + 1;
        }
        else
        {
            hbound = avg;
        }
    }
    while(monster_strength >= best[avg])
    {
        ++avg;
    }
    while(monster_strength < best[avg-1])
    {
        --avg;
    }
    return avg;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>C;
    for(int i=0; i<N; i++)
    {
        cin>>c>>d>>h;
        best[c] = max(best[c], d*h);
    }
    for(int i=1; i<MAXC; i++)
    {
        for(int j=i; j<=C; j += i)
        {
            best[j] = max(best[j], best[i]*(j/i));
        }
    }
    for(int i=1; i<=C; i++)
    {
        best[i] = max(best[i], best[i-1]);
    }
    cin>>M;
    for(int i=0; i<M; i++)
    {
        cin>>D>>H;
        cout<<solve(D*H)<<endl;
    }
}