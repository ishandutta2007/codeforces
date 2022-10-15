#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN][5];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) 
            for(int j=0;j<5;j++)
                scanf("%d",&a[i][j]);
        int now=0;
        for(int i=1;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<5;j++) if(a[i][j]<a[now][j]) cnt++;
            if(cnt>=3) now=i;
        }
        bool f=true;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<5;j++) if(a[i][j]<a[now][j]) cnt++;
            if(cnt>=3) f=false;
        }
        if(!f) puts("-1"); else printf("%d\n",now+1);
    }
    return 0;
}