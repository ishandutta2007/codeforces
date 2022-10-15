#include<bits/stdc++.h>
#define MAXN 200005
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
        bool f=true;
        for(int i=1;i<=n;i++) if(a[i]!=i) f=false;
        if(f) {puts("0"); continue;}
        int l=INF,r=-INF,cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=i) 
            {
                l=min(l,i);
                r=max(r,i);
                cnt++;
            }
        }
        if(r-l+1==cnt) puts("1"); else puts("2");
    }
    return 0;
}