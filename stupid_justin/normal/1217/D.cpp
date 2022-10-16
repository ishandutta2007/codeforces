#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,m;
int head[N],cnt,in[N],out[N],tot;
queue<int> Q;
struct Edge
{
    int from,to,next;
}edge[N];

void add(int a,int b)
{
    cnt++;
    edge[cnt].from=a;
    edge[cnt].to=b;
    edge[cnt].next=head[a];
    head[a]=cnt;
}

int topo()
{
    for(int i=1;i<=n;i++)
    {
        if(!in[i])
        {
            Q.push(i);
            tot++;
        }
    }
    while(!Q.empty())
    {
        int temp=Q.front();
        Q.pop();
        for(int i=head[temp];i !=-1;i=edge[i].next)
        {
            int to=edge[i].to;
            in[to]--;
            if(!in[to])
            {
                Q.push(to);
                tot++;
            }
        }
    }
    if(tot!=n)
        return 1;
    else
        return 0;
}

int main()
{
    cin>>n>>m;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        in[b]++,out[a]++;
        add(a,b);
    }
    if(topo())
    {
        printf("2\n");
        int flag=1;
        for(int i=1;i<=cnt;i++)
        {
            int a=edge[i].from,b=edge[i].to;
            if(flag)
            {
                if(a<b)
                    printf("1");
                else
                    printf("2");
                flag=0;
            }
            else
            {
                if(a<b)
                    printf(" 1");
                else
                    printf(" 2");
            }
        }
        printf("\n");
    }
    else
    {
        printf("1\n1");
        for(int i=1;i<m;i++)
            printf(" 1");
        printf("\n");
    }
    return 0;
}