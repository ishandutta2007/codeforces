#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#define MAXN 500500
using namespace std;
typedef pair<int, int> pii;
int N;
set<pii> s;
pii x[MAXN];
vector<int> conn[MAXN];
int tot, tot2;
bool vis[MAXN];
void dfs(int node)
{
    if(vis[node])
    {
        return;
    }
    vis[node] = true;
    ++tot2;
    for(int i=0; i<conn[node].size(); i++)
    {
        dfs(conn[node][i]);
    }
}
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>x[i].first>>x[i].second;
    }
    sort(x, x+N);
    for(int i=0; i<N; i++)
    {
        for(set<pii>::iterator it = s.lower_bound(make_pair(x[i].first, 0)); it != s.lower_bound(make_pair(x[i].second, 0)); ++it)
        {
            conn[i].push_back(it -> second);
            conn[it -> second].push_back(i);
            ++tot;
            if(tot == N)
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        s.insert(make_pair(x[i].second, i));
    }
    dfs(0);
    if(tot2 == N) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}