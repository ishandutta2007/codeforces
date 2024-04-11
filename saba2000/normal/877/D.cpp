#include<bits/stdc++.h>
using namespace std;
int a[1009][1009];
int f[1009][1009][3];
int d[1009][1009][3];
main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
    {
        char c;
        scanf(" %c",&c);
        if(c=='.') a[i][j]=1;
    }
    /*
     5 5 2
.#...
...#.
#.#..
.##.#
.....
1 1 5 5
   */
    int x,y,p,q;
    cin>>x>>y>>p>>q;
    queue<pair<pair<int,int>,int > > b;
    b.push({{x,y},-1});
    while(b.size()>0)
    {
        pair<pair<int,int>,int > fr=b.front();b.pop();
        int cx=fr.first.first,cy=fr.first.second,dr=fr.second;
        if(cx==p && cy==q) {cout<<d[cx][cy][dr]<<endl; return 0;}
        if(f[cx][cy][1-dr]==1) continue;
        if(dr!=0){
            for (int i=cx-1; ; i--)
            {
                if(i==0 || a[i][cy]==0) break;
                if(f[i][cy][0]==0)
                {
                    d[i][cy][0]=d[cx][cy][dr]+(cx-i-1)/k+1;
                    f[i][cy][0]=1;
                    b.push({{i,cy},0});
                }
            }
            for (int i=cx+1; ; i++)
            {
                if(i==n+1 || a[i][cy]==0) break;
                if(f[i][cy][0]==0)
                {
                    d[i][cy][0]=d[cx][cy][dr]+(i-cx-1)/k+1;
                    f[i][cy][0]=1;
                    b.push({{i,cy},0});
                }
            }
            }
            if(dr!=1){
            for (int i=cy-1; ; i--)
            {
                if(i==0 || a[cx][i]==0) break;
                if(f[cx][i][1]==0)
                {
                    d[cx][i][1]=d[cx][cy][dr]+(cy-i-1)/k+1;
                    f[cx][i][1]=1;
                    b.push({{cx,i},1});
                }
            }
            for (int i=cy+1; ; i++)
            {
                if(i==m+1 || a[cx][i]==0) break;
                if(f[cx][i][1]==0)
                {
                    d[cx][i][1]=d[cx][cy][dr]+(i-cy-1)/k+1;
                    f[cx][i][1]=1;
                    b.push({{cx,i},1});
                }
            }
            }

    }
    cout<<-1<<endl;

}