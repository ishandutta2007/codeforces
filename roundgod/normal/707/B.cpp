#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#define MAXN 100000
#define INF 1000000001
using namespace std;
bool store[MAXN];
int roads[MAXN][3];
int n,m,k;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    memset(store,false,sizeof(store));
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&roads[i][0],&roads[i][1],&roads[i][2]);
        roads[i][0]--;
        roads[i][1]--;
    }
    for(int i=0;i<k;i++)
    {
        int x;
        scanf("%d",&x);
        x--;
        store[x]=true;
    }
    int mini=INF;
    for(int i=0;i<m;i++)
    {
        if((store[roads[i][0]]==true&&store[roads[i][1]]==false)||(store[roads[i][0]]==false&&store[roads[i][1]]==true))
            mini=min(mini,roads[i][2]);
    }
    printf("%d\n",mini==INF?-1:mini);
    return 0;
}