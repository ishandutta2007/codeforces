#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,b[MAXN];
bool valid[2*MAXN];
int suf[2*MAXN],pre[2*MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=2*n;i++) valid[i]=false;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&b[i]);
            valid[b[i]]=true;
        }
        suf[2*n+1]=0;
        for(int i=2*n;i>=1;i--) {suf[i]=suf[i+1]; if(!valid[i]) suf[i]++;}
        pre[0]=0;
        for(int i=1;i<=2*n;i++) {pre[i]=pre[i-1]; if(!valid[i]) pre[i]++;}
        int cnt=0,need=0;
        for(int i=1;i<=2*n;i++)
        {
            if(valid[i])
            {
                if(need+1>suf[i+1]) break;
                else
                {
                    cnt++;
                    need++;
                }
            }
            else if(need) need--;
        }
        int cnt2=0;
        need=0;
        for(int i=2*n;i>=1;i--)
        {
            if(valid[i])
            {
                if(need+1>pre[i-1]) break;
                else
                {
                    cnt2++;
                    need++;
                }
            }
            else if(need) need--;
        }
        printf("%d\n",cnt-(n-cnt2)+1);
    }
}