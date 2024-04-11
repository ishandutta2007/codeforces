#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,h,w;
int a[25][25];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&h,&w);
        memset(a,0,sizeof(a));
        if(h&1)
        {
            for(int i=1;i<=h;i+=2) a[i][1]=a[i][w]=1;
            for(int i=1;i<=w;i+=2) if(!a[1][i+1]) a[1][i]=a[h][i]=1;
        }
        else if(w&1)
        {
            for(int i=1;i<=w;i+=2) a[1][i]=a[h][i]=1;
            for(int i=1;i<=h;i+=2) if(!a[i+1][1]) a[i][1]=a[i][w]=1;
        }
        else
        {
            for(int i=2;i<=w-2;i+=2) a[1][i]=1;
            for(int i=2;i<=h-2;i+=2) a[i][w]=1;
            for(int i=w-1;i>=3;i-=2) a[h][i]=1;
            for(int i=h-1;i>=3;i-=2) a[i][1]=1; 
        }
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++) printf("%d",a[i][j]);
            puts("");
        }
    }
    return 0;
}