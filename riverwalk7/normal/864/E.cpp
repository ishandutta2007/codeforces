#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXN 110
#define MAXV 2010
using namespace std;
int N;
struct item
{
    int t, d, p, id;
    item()
    {
        t = d = p = id = 0;
    }
    bool operator <(const item &rhs) const
    {
        return d < rhs.d;
    }
};
item x[MAXN];
int DP[MAXN][MAXV];
bool used[MAXN][MAXV][MAXN];
int best, cur, ans;
int main()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        cin>>x[i].t>>x[i].d>>x[i].p;
        x[i].id = i;
    }
    sort(x+1, x+N+1);
    for(int i=1; i<=N; i++)
    {
        for(int j=0; j<x[i].d; j++)
        {
            DP[i][j] = DP[i-1][j];
            for(int k=1; k<i; k++)
            {
                used[i][j][k] = used[i-1][j][k];
            }
            if(j >= x[i].t && ((DP[i-1][j-x[i].t] + x[i].p) > DP[i][j]))
            {
                DP[i][j] = DP[i-1][j-x[i].t] + x[i].p;
                for(int k=1; k<i; k++)
                {
                    used[i][j][k] = used[i-1][j-x[i].t][k];
                }
                used[i][j][i] = true;
            }
        }
    }
    for(int i=0; i<MAXV; i++)
    {
        if(DP[N][i] > best)
        {
            best = DP[N][i];
            cur = i;
        }
    }
    cout<<best<<endl;
    for(int i=1; i<=N; i++)
    {
        if(used[N][cur][i])
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    for(int i=1; i<=N; i++)
    {
        if(used[N][cur][i]&&ans>1)
        {
            cout<<x[i].id<<" ";
            ans--;
        }
        else if(used[N][cur][i]&&ans==1)
        {
            cout<<x[i].id<<endl;
        }
    }
}