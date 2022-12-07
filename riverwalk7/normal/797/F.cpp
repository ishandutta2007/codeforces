#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
#define INF (ll)(1e15)
#define MAXN 5050
using namespace std;
typedef long long ll;
struct hole
{
    ll p, c;
    hole()
    {
        p = c = 0;
    }
    bool operator <(const hole & rhs) const
    {
        return p<rhs.p;
    }
};
int N, M;
ll x[MAXN];
hole h[MAXN];
ll DP[MAXN][2];
ll prefix[MAXN];
deque<int> q;
int main()
{
    cin>>N>>M;
    for(int i=1; i<=N; i++)
    {
        cin>>x[i];
    }
    for(int i=1; i<=M; i++)
    {
        cin>>h[i].p>>h[i].c;
    }
    sort(x+1, x+N+1);
    sort(h+1, h+M+1);
    for(int i=1; i<=N; i++)
    {
        DP[i][0] = INF;
    }
    for(int i=1; i<=M; i++)
    {
        prefix[0] = 0;
        q.push_back(0);
        for(int j=1; j<=N; j++)
        {
            prefix[j] = prefix[j-1] + abs(x[j]-h[i].p);
            while(!q.empty() && DP[j][(i+1)%2]-prefix[j] < DP[q.front()][(i+1)%2]-prefix[q.front()])
            {
                q.pop_front();
            }
            q.push_front(j);
            if(q.back() < j-h[i].c)
            {
                q.pop_back();
            }
            DP[j][i%2] = DP[q.back()][(i+1)%2] + prefix[j] - prefix[q.back()];
        }
        q.clear();
    }
    if(DP[N][M%2] == INF)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<DP[N][M%2]<<endl;
    }
}