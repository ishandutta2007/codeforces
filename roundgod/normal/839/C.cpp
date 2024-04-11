#include<bits/stdc++.h>
#define MAXN 100001
#define INF 100000000
using namespace std;
vector<int> G[MAXN];
bool used[MAXN];
int n;
double find(int x)
{
    used[x]=true;
    int sz=G[x].size();
    int t=sz;
    for(int i=0;i<t;i++)
        if(used[G[x][i]]) sz--;
    double p=0;
    for(int i=0;i<t;i++)
    {
         if(!used[G[x][i]]) p+=((find(G[x][i])+1)/sz);
    }
    return p;
}
int main()
{
    scanf("%d",&n);
    memset(used,false,sizeof(used));
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    printf("%0.16f\n",find(1));
    return 0;
}