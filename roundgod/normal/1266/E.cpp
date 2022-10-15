#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],q;
int has[MAXN];
ll ans;
void add(int x)
{
    has[x]++;
    if(has[x]<=a[x]) ans--;
}
void dec(int x)
{
    has[x]--;
    if(has[x]<a[x]) ans++;
}
map<P,int> s;
int main()
{
    scanf("%d",&n);
    ans=0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        ans+=a[i];
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(s[P(x,y)])
        {
            dec(s[P(x,y)]);
            s[P(x,y)]=0;
        }
        if(z!=0)
        {
            s[P(x,y)]=z;
            add(z);
        }
        printf("%lld\n",ans);
    }
    return 0;
}