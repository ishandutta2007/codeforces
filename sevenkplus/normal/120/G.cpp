#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
int n,t,m,w[110],d[110][110],a[110][2];string s[110];int c[110];vector<string> A[110];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++)
    {
        int x0,y0,x1,y1;
        scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
        a[i][0]=x0+y1,a[i][1]=y0+x1;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)cin>>s[i]>>c[i];
    queue<int> q;
    for(int i=0;i<m;i++)q.push(i);
    for(int xx=0,yy=0;!q.empty();)
    {
        for(int tt=0;!q.empty();)
        {
            int x=q.front();q.pop();
            int st=max(1,c[x]-a[xx][yy]-d[xx][x]);
            if(tt+st>t){d[xx][x]+=t-tt,q.push(x);break;}
            else A[xx].push_back(s[x]),tt+=st;
            if(tt==t)break;
        }
        xx++;if(xx==n)xx=0,yy^=1;
    }
    for(int i=0;i<n;i++)
    {
        cout<<(int)A[i].size();
        for(int j=0;j<(int)A[i].size();j++)
            cout<<" "<<A[i][j];
        cout<<endl;
    }
    return 0;
}