#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define MAXN 200100
using namespace std;
typedef pair<int, int> pii;
bool s[10][10][MAXN];
vector<int> t[10][10];
vector<pii> conn[MAXN];
vector<int> y;
int N, M, K;
int u, v, w;
bool p[10][10];
bool g[10][10][10][10];
int ans;
bool check()
{
    for(int i=0; i<y.size(); i++)
    {
        if(p[i+1][y[i]])
        {
            return false;
        }
        for(int j=i+1; j<y.size(); j++)
        {
            if(!g[i+1][y[i]][j+1][y[j]])
            {
                return false;
            }
        }
    }
    return true;
}
void solve(int x)
{
    if(x == K)
    {
        ans += check();
        y.erase(--y.end());
        return;
    }
    for(int i=0; i<=x; i++)
    {
        y.push_back(i);
        solve(x+1);
    }
    y.erase(--y.end());
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M>>K;
    for(int i=0; i<M; i++)
    {
        cin>>u>>v>>w;
        conn[u].push_back(make_pair(w, v));
    }
    for(int i=1; i<=N; i++)
    {
        sort(conn[i].begin(), conn[i].end());
        for(int j=0; j<conn[i].size(); j++)
        {
            int d = conn[i].size();
            int cur = conn[i][j].second;
            if(!s[d][j][cur])
            {
                s[d][j][cur] = true;
                t[d][j].push_back(cur);
            }
            else
            {
                p[d][j] = true;
            }
        }
    }
    for(int i=1; i<=K; i++)
    {
        for(int j=0; j<i; j++)
        {
            sort(t[i][j].begin(), t[i][j].end());
        }
    }
    for(int i=1; i<=K; i++)
    {
        for(int j=0; j<i; j++)
        {
            for(int k=1; k<=K; k++)
            {
                for(int l=0; l<k; l++)
                {
                    g[i][j][k][l] = true;
                    int counter = 0;
                    for(int m=0; m<t[i][j].size(); m++)
                    {
                        while(counter < t[k][l].size() && t[i][j][m] > t[k][l][counter])
                        {
                            ++counter;
                        }
                        if(counter == t[k][l].size())
                        {
                            break;
                        }
                        if(t[k][l][counter] == t[i][j][m])
                        {
                            g[i][j][k][l] = false;
                        }
                    }
                }
            }
        }
    }
    solve(0);
    cout<<ans<<endl;
}