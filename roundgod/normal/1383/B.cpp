#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int s=0;
        for(int i=1;i<=n;i++) s^=a[i];
        if(s==0) puts("DRAW");
        else
        {
            int k=0;
            for(int i=0;i<=30;i++) if(s&(1<<i)) k=i;
            int cnt=0;
            for(int i=1;i<=n;i++) if(a[i]&(1<<k)) cnt++;
            if((cnt%4==3)&&((n-cnt)%2==0)) puts("LOSE"); else puts("WIN");
        }
        
    }
}