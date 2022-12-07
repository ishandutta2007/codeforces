#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#define MAXN 100100
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int N, M, Q;
vector<int> indeg[MAXN];
ll x[MAXN], y[MAXN];
int u, v, w;
ll ans;
int cur;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>N>>M;
    for(int i=0; i<M; i++)
    {
        cin>>u>>v;
        if(u > v)
        {
            swap(u, v);
        }
        indeg[u].push_back(v);
        ++x[u]; ++y[v];
    }
    for(int i=1; i<=N; i++)
    {
        ans += x[i]*y[i];
    }
    cin>>Q;
    cout<<ans<<endl;
    for(int i=0; i<Q; i++)
    {
        cin>>w;
        while(!indeg[w].empty())
        {
            cur = *(--indeg[w].end());
            indeg[w].erase(--indeg[w].end());
            indeg[cur].push_back(w);
            ans -= x[cur]*y[cur];
            ans -= x[w]*y[w];
            --y[cur]; ++ x[cur];
            ++y[w]; --x[w];
            ans += x[cur]*y[cur];
            ans += x[w]*y[w];
        }
        cout<<ans<<endl;
    }
}