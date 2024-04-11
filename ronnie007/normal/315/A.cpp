#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;



int n;
int a[150];
int b[150];
int used[150];
int ans=0;


void input();
void solve();
void BFS(int vertex);


int main()
    {
    input();
    solve();
    return 0;
    }


void input()
    {
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)
        {
        scanf("%d%d",&a[i],&b[i]);
        }
    }

void solve()
    {
    int i;
    for(i=1;i<=n;i++)
        {
        if(used[i]==0)
            {
            ///printf("%d\n",ans);
            BFS(i);
            }
        }
    for(i=1;i<=n;i++)
        {
        if(used[i]==0)ans++;
        ///cout<<ans<<"\n";
        }
    printf("%d\n",ans);
    }


void BFS(int vertex)
    {
    queue < int> q;
    while(q.empty()==false)q.pop();
    int i;
    int p;
    int fl=0;
    q.push(vertex);
    while(q.empty()==false)
        {
        p=q.front();
        q.pop();
        if(p!=vertex || fl==1){used[p]=1;fl=1;}
        for(i=1;i<=n;i++)
            {
            if(i==p)continue;
            if(a[i]==b[p] && used[i]==0)
                {
                q.push(i);
                }
            }
        }
    }