#include <iostream>
# include <cstdlib>
# include <algorithm>
#include<cstdio>
# include <vector>
#include <cmath>
#include <map>
#include<set>
#include <stack>
using namespace std;
vector<int> a[100001];
int m=0;
int edges[1000001][2];
bool vis[1000000];
int done[1000000];
int num[1000000];
struct vertex
{
    int idx;
    int dist;
} len[1000000];
bool comp(vertex a,vertex b)
{
    return a.dist<b.dist;
}
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
        cin>>len[i].dist,len[i].idx=i,a[len[i].dist].push_back(i);
    sort(len,len+n,comp);
    int is=n;
    done[0]=1;
    for (int i=0;i<n;i++)
    {
        int x=len[i].dist+1;
        int p=a[x].size();
        for (int j=done[x];j<p;j++)
        {
            if (num[len[i].idx]==k)
                break;
            if (done[x]==p)
                break;
            num[len[i].idx]++;
            is+=vis[len[i].idx];
            num[a[x][j]]++;
            vis[len[i].idx]=1;
            is-=vis[len[i].idx];
            edges[m][0]=len[i].idx+1;
            edges[m++][1]=a[x][j]+1;
            is+=vis[a[x][j]];
            vis[a[x][j]]=1;
            is-=vis[a[x][j]];
            done[x]++;
        }
    }
    is=0;
    for (int i=0;i<=n;i++)
    {
        if (done[i]<a[i].size())
            is=1;
    }
    if (is>0)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<m<<endl;
    for (int i=0;i<m;i++)
    {
        cout<<edges[i][0]<<" "<<edges[i][1]<<endl;
    }
}