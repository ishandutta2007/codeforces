#include<bits/stdc++.h>
#define MAXN 300005
using namespace std;
int n,q;
queue<int> que[MAXN];
queue<int> save;
bool mark[MAXN];
int main()
{
    scanf("%d %d",&n,&q);
    memset(mark,false,sizeof(mark));
    int cnt=0,ans=0;
    for(int i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==1)
        {
            cnt++;
            save.push(cnt);
            que[y].push(cnt);
            ans++;
        }
        else if(x==2)
        {
            while(!que[y].empty())
            {
                if(!mark[que[y].front()]) ans--;
                mark[que[y].front()]=true;
                que[y].pop();
            }
        }
        else
        {
            while(!save.empty())
            {
                int p=save.front();
                if(p>y) break;
                if(!mark[p]) ans--;
                mark[p]=true;
                save.pop();
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}