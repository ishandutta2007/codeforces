#include<bits/stdc++.h>
#define intt long long
#define fr first
#define sc second
#define ii pair<int,int>
#define mk make_pair
#define pb push_back
using namespace std;
int visit[5004][5004];
     int a[5004][5004];
int main()
{
    int n,m;
    cin>>n>>m;
    int i,j;
     char x;
    for(i=1; i<=n; i++)
    {
        a[i][0]=0;
        x=getchar();
        for(j=1; j<=m; j++)
        {


            x = getchar();
            if(x=='1')
                a[i][j]=1+a[i][j-1];
            else
                a[i][j]=0;
            visit[j][a[i][j]]++;
        }
    }


int maxx=0;
    for(i=1; i<=m; i++)
    {
        for(j=5000;j>=1;j--)
        {
            visit[i][j]+=visit[i][j+1];
            maxx=max(maxx,visit[i][j]*j);
        }
    }
    cout<<maxx;





    return 0;
}