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
        for(int i=0;i<n;i++) 
        {
            scanf("%d",&a[i]);
            if(a[i]<0) a[i]=-a[i];
        }
        bool f=false;
        sort(a,a+n);
        for(int mask=0;mask<(1<<n);mask++)
        {
            int s=0;
            for(int i=0;i<n;i++) if(mask&(1<<i)) s+=a[i];
            for(int mask2=0;mask2<(1<<n);mask2++)
            {
                if(mask2==mask) continue;
                int ss=0;
                for(int j=0;j<n;j++) if(mask2&(1<<j)) ss+=a[j];
                if(s==ss) f=true; 
            }
        }
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}