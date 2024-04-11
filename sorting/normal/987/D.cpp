#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const long long N=100007;
const long long K=107;

long long n,m,k,s;
long long a[N];
long long dp[N][K];
bool used[N];

vector<long long> v[N];

long long bfs(long long c)
{
    queue<long long> q;
    long long i,u;

    for(long long i=1;i<=n;i++)
        used[i]=0;

    for(i=1;i<=n;i++)
        if(a[i]==c)
        {
            dp[i][c]=0;
            q.push(i);
            used[i]=1;
        }

    while(!q.empty())
    {
        u=q.front();
        q.pop();

        for(i=0;i<v[u].size();i++)
        {
            long long to=v[u][i];

            if(!used[to])
            {
                dp[to][c]=dp[u][c]+1;
                q.push(to);
                used[to]=1;
            }
        }
    }
}

int  main ()
{
    long long i,x,y,res,j;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>k>>s;

    for(i=1;i<=n;i++)
        cin>>a[i];

    for(i=0;i<m;i++)
    {
        cin>>x>>y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(i=1;i<=k;i++)
        bfs(i);

    for(i=1;i<=n;i++)
        sort(dp[i]+1,dp[i]+k+1);

    for(i=1;i<=n;i++)
    {
        res=0;

        for(j=1;j<=s;j++)
            res+=dp[i][j];
        cout<<res<<" ";
    }
    cout<<endl;

    return 0;
}