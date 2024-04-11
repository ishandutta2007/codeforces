#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
ll a[MAXN],b[MAXN];
int nxt[MAXN];
int val[MAXN];
bool swapped;
void go(int l1,int r1,int l2,int r2)
{
    if(swapped) {swap(l1,l2); swap(r1,r2);}
    printf("%d\n",r1-l1+1);
    for(int i=l1;i<=r1;i++) printf("%d%c",i,i==r1?'\n':' ');
    printf("%d\n",r2-l2+1);
    for(int i=l2;i<=r2;i++) printf("%d%c",i,i==r2?'\n':' ');
    exit(0);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++) 
    {
        scanf("%lld",&b[i]);
        b[i]+=b[i-1];
    }
    swapped=false;
    if(a[n]>b[n]) 
    {
        for(int i=1;i<=n;i++) swap(a[i],b[i]);
        swapped=true;
    }
    int now=1;
    for(int i=1;i<=n;i++)
    {
        while(b[now]<a[i]) now++;
        if(b[now]==a[i]) go(1,i,1,now);
        if(val[b[now]-a[i]])
        {
            int x=val[b[now]-a[i]];
            go(x+1,i,nxt[x]+1,now);
        }
        nxt[i]=now;
        val[b[now]-a[i]]=i;
    }
    assert(0);
    return 0;
}