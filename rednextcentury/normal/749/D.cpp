#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[1000000];
vector<int> vec[1000000];
int vis[1000000];
int sz[1000000];
int last[1000000];
int num[1000000];
int cur[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].first,&a[i].second);
        vec[a[i].first].push_back(i);
    }
    sz[n-1]=1;
    vis[a[n-1].first]=1;
    for (int i=n-2;i>=0;i--)
    {
        if (++vis[a[i].first]==1)
        {
            sz[i]=sz[i+1]+1;
        }
        else
            sz[i]=sz[i+1];
    }
    last[0]=-1;
    for (int i=1;i<n;i++)
    {
        if (sz[i]==sz[i-1])
            last[i]=last[i-1];
        else last[i]=i-1;
    }
    int q;
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        int m;
        scanf("%d",&m);
        for (int j=0;j<m;j++)
        {
            int x;
            scanf("%d",&x);
            cur[x]=i;
        }
        int win=-1;
        int winat=-1;
        for (int p=n-1;p>=0;)
        {
            if (cur[a[p].first]!=i)
            {
                win=a[p].first;
                winat=p;
                while(p>=0 && sz[p]<=m+1 && (a[p].first==win || cur[a[p].first]==i))
                    p=last[p];
                winat=p;
                break;
            }
            p=last[p];
        }
        if (win==-1)
        {
            printf("0 0\n");
        }
        else{
            int x=*lower_bound(vec[win].begin(),vec[win].end(),winat);
            printf("%d %d\n",win,a[x].second);
        }
    }
}