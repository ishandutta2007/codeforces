#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
#define MAX_N 200000

int N, M;
struct S{
    int idx;
    long long data;
    bool operator <(const S &a)const{
        return data>a.data;
    }
};
priority_queue<S> pq;
vector<S> gp[MAX_N+1];
long long arr[MAX_N+1];
int v, u;
long long w;
bool visited[MAX_N+1];
long long ans[MAX_N+1];

int main()
{
    scanf("%d %d", &N, &M);
    for(int i=1; i<=M; i++)
    {
        scanf("%d %d %lld", &v, &u, &w);
        gp[v].push_back({u, w});
        gp[u].push_back({v, w});
    }
    for(int i=1; i<=N; i++)
    {
        scanf("%lld", &arr[i]);
        pq.push({i, arr[i]});
    }
    S T;
    while(!pq.empty())
    {
        T=pq.top();
        pq.pop();
        if(!visited[T.idx])
        {
            ans[T.idx]=T.data;
            visited[T.idx]=true;
            for(int i=0; i<gp[T.idx].size(); i++)
            {
                if(!visited[gp[T.idx][i].idx])
                {
                    pq.push({gp[T.idx][i].idx, T.data+2*gp[T.idx][i].data});
                }
            }
        }
    }
    for(int i=1; i<=N; i++)
    {
        printf("%lld ", ans[i]);
    }
    return 0;
}