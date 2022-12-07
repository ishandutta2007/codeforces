#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 500500
using namespace std;
typedef long long ll;
vector<int> factors[2*MAXN];
ll c[2*MAXN][3];
ll N, x, y;
int a[MAXN];
ll ans, cur;
int main()
{
    ans = 1e18;
    for(int i=2; i<(2*MAXN); i++)
    {
        if(factors[i].empty())
        {
            for(int j=1; i*j < (2*MAXN); j++)
            {
                factors[i*j].push_back(i);
            }
        }
    }
    cin>>N>>x>>y;
    for(int i=0; i<(2*MAXN); i++)
    {
        c[i][2] = N;
    }
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
        for(int j=0; j<factors[a[i]].size(); j++)
        {
            c[factors[a[i]][j]][2]--;
            c[factors[a[i]][j]][0]++;
        }
        for(int j=0; j<factors[a[i]+1].size(); j++)
        {
            c[factors[a[i]+1][j]][2]--;
            c[factors[a[i]+1][j]][1]++;
        }
    }
    if(x < y)
    {
        for(int i=0; i<(2*MAXN); i++)
        {
            ans = min(ans, x*(N-c[i][0]));
        }
    }
    else if(x < (2*y))
    {
        for(int i=0; i<(2*MAXN); i++)
        {
            ans = min(ans, y*c[i][1] + x*c[i][2]);
        }
    }
    else
    {
        for(int i=0; i<(2*MAXN); i++)
        {
            cur = 0;
            if(c[i][2] <= N/2)
            {
                for(int j=0; j<N; j++)
                {
                    cur += min(x, y*((i-a[j]%i)%i));
                }
                ans = min(ans, cur);
            }
        }
    }
    cout<<ans<<endl;
}