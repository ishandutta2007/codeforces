#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a[40][40];int n,m,p;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m>>p;
    for(int i=0;i<p;i++)
    {
        int w;cin>>w;
        if(w==-1)
        {
            string s;cin>>s;bool F=0;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    if(a[i][j]==s)F=1,printf("%d %d\n",i,j),a[i][j]="";
            if(!F)puts("-1 -1");
            continue;
        }
        int x,y;string s;cin>>x>>y>>s;
        while(x<=n&&a[x][y]!=""){y++;if(y>m)x++,y=1;}
        if(x<=n)a[x][y]=s;
    }
    return 0;
}