#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int n,m;
string a[60];
int used[60][60];
int g=0;

void input();
void solve();
int canreach(int x,int y);
void dfs(int x,int y);


int main()
    {
    input();
    solve();
    return 0;
    }


void input()
    {
    cin>>n>>m;
    int i,j;
    for(i=0;i<n;i++)
        {
        cin>>a[i];
        for(j=0;j<m;j++)
            {
            if(a[i][j]=='#')g++;
            }
        }
    }

void solve()
    {
    if(g==1 || g==2){printf("-1\n");return ;}
    int i,j;
    int br=70;
    for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
            {
            if(a[i][j]=='#' && canreach(i,j)==0)
                {
                ///printf("%d %d\n",i,j);
                printf("1\n");
                return ;
                }
            }
        }
    ///printf("ghere\n");
    int br1=0;
    for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
            {
            if(a[i][j]!='#')continue ;
            br1=0;
            if(i>0 && a[i-1][j]=='#')br1++;
            if(j>0 && a[i][j-1]=='#')br1++;

            if(i<n-1 && a[i+1][j]=='#')br1++;
            if(j<m-1 && a[i][j+1]=='#')br1++;

            ///printf("for i=%d and j=%d br1 is %d\n",i,j,br1);

            if(br1<br)br=br1;
            }
        }
    printf("%d\n",br);
    }



int canreach(int x,int y)
    {
    a[x][y]='.';
    int i,j;
    int s,t;
    for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
            {
            used[i][j]=0;
            }
        }
    for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
            {
            if(a[i][j]=='#')break;
            }
        if(a[i][j]=='#')break;
        }
    ///printf("%d %d\n",i,j);
    dfs(i,j);
    for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
            {
            if(a[i][j]=='#' && used[i][j]==0){a[x][y]='#';return 0;}
            }
        }
    a[x][y]='#';
    return 1;
    }



void dfs(int x,int y)
    {
    used[x][y]=1;

    if(x>0 && used[x-1][y]==0 && a[x-1][y]=='#')dfs(x-1,y);
    if(y>0 && used[x][y-1]==0 && a[x][y-1]=='#')dfs(x,y-1);

    if(x<n-1 && used[x+1][y]==0 && a[x+1][y]=='#')dfs(x+1,y);
    if(y<m-1 && used[x][y+1]==0 && a[x][y+1]=='#')dfs(x,y+1);
    }