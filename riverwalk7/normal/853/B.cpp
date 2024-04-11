#include <iostream>
#include <queue>
#include <algorithm>
#define MAXN 100100
using namespace std;
typedef long long ll;
struct flight
{
    ll d, f, t, c;
    flight()
    {
        d = f = t = c = 0;
    }
    bool operator <(const flight &rhs) const
    {
        return d < rhs.d;
    }
};
int N, M, K;
flight x[MAXN];
ll ans[MAXN][2];
ll best[MAXN][2];
bool possible[MAXN][2];
ll g;
int num;
int counter;
int main()
{
    cin>>N>>M>>K;
    for(int i=0; i<M; i++)
    {
        cin>>x[i].d>>x[i].f>>x[i].t>>x[i].c;
    }
    for(int i=1; i<=N; i++)
    {
        for(int j=0; j<2; j++)
        {
            best[i][j] = 1e18;
        }
    }
    sort(x, x+M);
    for(int i=0; i<M; i++)
    {
        if(i!=0)
        {
            ans[i][0] = ans[i-1][0];
        }
        if(x[i].t==0)
        {
            if(best[x[i].f][0]==1e18)
            {
                ++num;
                ans[i][0] += x[i].c;
            }
            else
            {
                ans[i][0] += min((ll)0, x[i].c-best[x[i].f][0]);
            }
            best[x[i].f][0] = min(best[x[i].f][0], x[i].c);
        }
        if(num==N)
        {
            possible[i][0] = true;
        }
    }
    for(int i=M-1; i>=0; i--)
    {
        ans[i][1] = ans[i+1][1];
        if(x[i].f==0)
        {
            if(best[x[i].t][1]==1e18)
            {
                ++num;
                ans[i][1] += x[i].c;
            }
            else
            {
                ans[i][1] += min((ll)0, x[i].c-best[x[i].t][1]);
            }
            best[x[i].t][1] = min(best[x[i].t][1], x[i].c);
        }
        if(num==2*N)
        {
            possible[i][1] = true;
        }
    }
    g = 1e18;
    for(int i=0; i<M; i++)
    {
        while(counter < M && x[counter].d <= (x[i].d+K))
        {
            ++counter;
        }
        if(possible[counter][1]&&possible[i][0])
        {
            g = min(g, ans[i][0] + ans[counter][1]);
        }
    }
    if(g==1e18)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<g<<endl;
    }
}