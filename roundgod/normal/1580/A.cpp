#include<bits/stdc++.h>
#define MAXN 405
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define right sdkas
#define left sdkoads
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
char str[MAXN][MAXN];
int ca[MAXN],cb[MAXN],right[MAXN],left[MAXN],leftmax[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
        int ans=INF;
        for(int upper=1;upper<=n;upper++)
        {
            memset(ca,0,sizeof(ca));
            memset(cb,0,sizeof(cb));
            for(int lower=upper+1;lower<=n;lower++)
            {
                if(lower==upper+1)
                {
                    for(int i=1;i<=m;i++) ca[i]=(str[upper][i]=='0'?1:0)+(str[lower][i]=='0'?1:0);
                }
                else
                {
                    for(int i=1;i<=m;i++) 
                    {
                        if(str[lower][i]=='0') ca[i]++;
                        if(str[lower-1][i]=='0') ca[i]--; else ca[i]++;
                        if(str[lower-1][i]=='0') cb[i]++; 
                    }
                }
                if(lower-upper>=4)
                {
                    memset(right,0,sizeof(right));
                    memset(left,0,sizeof(left));
                    memset(leftmax,0,sizeof(leftmax));
                    left[0]=leftmax[0]=ca[1]-cb[1];
                    for(int i=1;i<=m;i++)
                    {
                        right[i]=(i==1?cb[i]:cb[i]+right[i-1]-cb[i-1]+ca[i-1]);
                        left[i]=(i==1?ca[i]-cb[i]:left[i-1]+cb[i-1]+ca[i]-cb[i]);
                        leftmax[i]=(i==1?left[i]:max(leftmax[i-1],left[i]));
                        if(i>=4) ans=min(ans,right[i]-leftmax[i-3]); 
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}