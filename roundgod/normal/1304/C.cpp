#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int q,n,m;
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        bool f=true;
        scanf("%d%d",&n,&m);
        ll l=m,r=m;
        int cur=0;
        for(int i=0;i<n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            l-=(x-cur); r+=(x-cur);
            if(l>z||r<y) f=false;
            l=max(l,(ll)y); r=min(r,(ll)z);
            cur=x;
        }
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}