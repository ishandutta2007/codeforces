#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int r[3],c[3];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int cnt[2]={0,0};
        for(int i=0;i<3;i++) 
        {
            scanf("%d%d",&r[i],&c[i]);
            if((r[i]+c[i])&1) cnt[1]++; else cnt[0]++;
        }
        int x,y;
        scanf("%d%d",&x,&y);
        int d=(x+y)&1;
        if(cnt[d]==2) 
        {
            bool f=true;
            for(int i=0;i<3;i++)
                if(((r[i]+c[i])&1)!=d)
                {
                    if((r[i]==1||r[i]==n)&&(c[i]==1||c[i]==n))
                        if((r[i]!=x)&&(c[i]!=y)) f=false;
                }
            if(f) puts("YES"); else puts("NO");
        }
        else
        {
            bool f=true;
            for(int i=0;i<3;i++)
                if(((r[i]+c[i])&1)==d)
                {
                    if((r[i]&1)!=(x&1)) f=false;
                    else if((r[i]==1||r[i]==n)&&(c[i]==1||c[i]==n))
                    {
                        if((r[i]!=x)&&(c[i]!=y)) f=false;
                    }
                }
            if(f) puts("YES"); else puts("NO");
        }
    }
    return 0;
}