#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#define MAXN 200200
using namespace std;
struct Edge
{
    int x, y, d;
    Edge()
    {
        x = y = d = 0;
    }
    bool operator <(const Edge &rhs) const
    {
        return d < rhs.d;
    }
};
int N, M;
int parent[MAXN];
int level[MAXN];
set<int> s;
int find_set(int node)
{
    if(parent[node] == node)
    {
        return node;
    }
    else
    {
        parent[node] = find_set(parent[node]);
        return parent[node];
    }
}
int merge_sets(int node1, int node2)
{
    if(level[node1] == level[node2])
    {
        ++level[node1];
    }
    if(level[node1] > level[node2])
    {
        swap(node1, node2);
    }
    parent[node1] = node2;
}
Edge e[MAXN];
int ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    for(int i=1; i<=N; i++)
    {
        parent[i] = i;
    }
    for(int i=1; i<=M; i++)
    {
        cin>>e[i].x>>e[i].y>>e[i].d;
    }
    sort(e+1, e+M+1);
    int counter = 1;
    int d1;
    int ans = 0; int k1, k2;
    for(int i=2; i<=M+1; i++)
    {
        if(e[i].d != e[i-1].d)
        {
            d1 = 0;
            s.clear();
            for(int j=counter; j<i; j++)
            {
                if(find_set(e[j].x) != find_set(e[j].y))
                {
                    ++d1;
                }
                s.insert(find_set(e[j].x));
                s.insert(find_set(e[j].y));
            }
            k1 = s.size();
            for(int j=counter; j<i; j++)
            {
                merge_sets(find_set(e[j].x), find_set(e[j].y));
            }
            s.clear();
            for(int j=counter; j<i; j++)
            {
                s.insert(find_set(e[j].x));
                s.insert(find_set(e[j].y));
            }
            k2 = s.size();
            counter = i;
            ans += (d1-k1+k2);
        }
    }
    cout<<ans<<endl;
}