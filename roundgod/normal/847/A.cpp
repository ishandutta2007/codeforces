#include<bits/stdc++.h>
#define MAXN 205
using namespace std;
vector< deque<int> > G;
int a[MAXN];
pair<int,int> b[MAXN];
int n;
int main()
{
    G.clear();
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        int l=-1,r=-1;
        for(int j=0;j<G.size();j++)
        {
            if(!G[j].empty())
            {
                if(y==G[j].front())
                    l=j;
                else if(x==G[j].back())
                    r=j;
            }
        }
        if(l==-1&&r==-1)
        {
            deque<int> deq;
            deq.push_back(i);
            G.push_back(deq);
        }
        else if(l==-1) G[r].push_back(i);
        else if(r==-1) G[l].push_front(i);
        else
        {
            G[r].push_back(i);
            while(!G[l].empty())
            {
                int p=G[l].front();
                G[l].pop_front();
                G[r].push_back(p);
            }
        }
    }
    int k=0;
    for(int i=0;i<G.size();i++)
        while(!G[i].empty())
        {
            int x=G[i].front();
            a[k]=x;
            k++;
            G[i].pop_front();
        }
      for(int i=0;i<k;i++)
      {
        if(i==0&&i==k-1) b[a[i]].first=b[a[i]].second=0;
        else if(i==0) b[a[i]].first=0, b[a[i]].second=a[i+1];
        else if(i==k-1) b[a[i]].first=a[i-1], b[a[i]].second=0;
        else b[a[i]].first=a[i-1],b[a[i]].second=a[i+1];
      }
      for(int i=1;i<=n;i++)
        printf("%d %d\n",b[i].first,b[i].second);
    return 0;
}