#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 110
using namespace std;
typedef long long ll;
int N;
int a[MAXN];
ll ans;
int cycle[MAXN];
bool vis[MAXN];
vector<ll> prime;
int dfs(int node)
{
    if(vis[node])
    {
        return 0;
    }
    else
    {
        vis[node] = true;
        return dfs(a[node]) + 1;
    }
}
int main()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            vis[j] = false;
        }
        cycle[i] = dfs(a[i]);
        if(!vis[i])
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=1; i<=N; i++)
    {
        if(cycle[i]%2==0)
        {
            cycle[i] /=2;
        }
    }
    bool flag;
    for(int i=2; i<100; i++)
    {
        flag = true;
        for(int j=2; j<i; j++)
        {
            if(i%j==0)
            {
                flag = false;
            }
        }
        if(flag)
        {
            prime.push_back(i);
        }
    }
    ans = 1;
    for(int i=0; i<25; i++)
    {
        for(int k=0; k<8; k++)
        {
            flag = false;
            for(int j=1; j<=N; j++)
            {
                if(cycle[j] % prime[i] == 0)
                {
                    cycle[j] /= prime[i];
                    flag = true;
                }
            }
            if(flag)
            {
                ans *= prime[i];
            }
        }
    }
    cout<<ans<<endl;
}