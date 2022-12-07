#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 5050
using namespace std;
int N, M;
int x, y;
int ans[MAXN];
int dist[MAXN];
int a[MAXN], b[MAXN];
bool flag;
int main()
{
    cin>>N>>M;
    for(int i=0; i<M; i++)
    {
        cin>>x>>y;
        if(x < y)
        {
            ans[i] = 1;
        }
        else
        {
            ans[i] = 2;
        }
        a[i] = x; b[i] = y;
    }
    for(int i=2; i<=N; i++)
    {
        dist[i] = 12345678;
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(i < N-1) dist[b[j]] = min(dist[b[j]], dist[a[j]]-1);
            else if(dist[b[j]] > dist[a[j]]-1) flag = true;
        }
    }
    if(!flag)
    {
        cout<<1<<endl;
        for(int i=0; i<M; i++)
        {
            cout<<1<<" ";
        }
    }
    else
    {
        cout<<2<<endl;
        for(int i=0; i<M; i++)
        {
            cout<<ans[i]<<" ";
        }
    }
}