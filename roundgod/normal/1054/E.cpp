/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-19 01:39:28
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
string st[MAXN][MAXN];
string ed[MAXN][MAXN];
struct req
{
    int x1,y1,x2,y2;
};
struct node
{
    int x,y,id;
};
vector<req> ans;
void process(int x1,int y1,int x2,int y2)
{
    //assert(st[x1][y1].size()>0);
    ans.push_back((req){x1,y1,x2,y2});
}
void Out(int a) 
{ 
    if (a < 0) 
    {
        putchar('-');
        a = -a;
    }  
    if (a >= 10)
    {
       Out(a / 10);  
    }
    putchar(a % 10 + '0');  
}
int main()
{
    scanf("%d%d",&n,&m);//(1,1):all 0,(n,m):all 1
    int s=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>st[i][j];
            s+=(int)st[i][j].size();
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>ed[i][j];
    queue<node> que;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=(int)st[i][j].size()-1;k>=0;k--) que.push((node){i,j,st[i][j][k]-'0'});
    while(que.size())
    {
        node p=que.front();que.pop();
        if((p.x==1&&p.y==1)||(p.x==n&&p.y==m))
        {
            process(p.x,p.y,1,m);
            que.push((node){1,m,p.id});
        }
        else if(p.id==0)
        {
            if(p.x==1||p.y==1) process(p.x,p.y,1,1);
            else {process(p.x,p.y,1,p.y); que.push((node){1,p.y,0});}
        }
        else
        {
            if(p.x==n||p.y==m) process(p.x,p.y,n,m);
            else {process(p.x,p.y,n,p.y); que.push((node){n,p.y,1});}
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<st[i][j]<<' ';
        cout<<endl;
    }*/
    for(int i=2;i<=n-1;i++)
        for(int j=2;j<=m-1;j++)
            for(int k=(int)ed[i][j].size()-1;k>=0;k--)
            {
                if(ed[i][j][k]=='0') {process(1,1,1,j); process(1,j,i,j);}
                else {process(n,m,n,j); process(n,j,i,j);}
            }
    for(int i=2;i<=n-1;i++)
        for(int k=(int)ed[i][1].size()-1;k>=0;k--)
        {
            if(ed[i][1][k]=='0') process(1,1,i,1);
            else {process(n,m,n,1); process(n,1,i,1);}
        }
    for(int i=2;i<=n-1;i++)
        for(int k=(int)ed[i][m].size()-1;k>=0;k--)
        {
            if(ed[i][m][k]=='0') {process(1,1,1,m); process(1,m,i,m);}
            else process(n,m,i,m); 
        }
    for(int i=2;i<=m-1;i++)
        for(int k=(int)ed[1][i].size()-1;k>=0;k--)
        {
            if(ed[1][i][k]=='0') process(1,1,1,i);
            else {process(n,m,1,m); process(1,m,1,i);}
        }
    for(int i=2;i<=m-1;i++)
        for(int k=(int)ed[n][i].size()-1;k>=0;k--)
        {
            if(ed[n][i][k]=='0') {process(1,1,n,1); process(n,1,n,i);}
            else process(n,m,n,i); 
        }
    string need1=ed[1][m]+ed[1][1];
    string need2=ed[n][1]+ed[n][m];
    for(int k=(int)need1.size()-1;k>=0;k--) if(need1[k]=='0') process(1,1,1,m); else process(n,m,1,m);
    for(int k=(int)need2.size()-1;k>=0;k--) if(need2[k]=='0') process(1,1,n,1); else process(n,m,n,1);
    for(int i=0;i<(int)ed[1][1].size();i++) process(1,m,1,1);
    for(int i=0;i<(int)ed[n][m].size();i++) process(n,1,n,m);

   /* for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<st[i][j]<<' ';
        cout<<endl;
    }
    //assert((int)ans.size()<=4*s);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            assert(st[i][j]==ed[i][j]);*/
    printf("%d\n",(int)ans.size());
    for(int i=0;i<(int)ans.size();i++)
    {
        Out(ans[i].x1);putchar(' ');Out(ans[i].y1);putchar(' ');
        Out(ans[i].x2);putchar(' ');Out(ans[i].y2);putchar('\n');
    }
    return 0;
}