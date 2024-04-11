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
int t,n,k,a[MAXN],b[MAXN];
map<int,int> mp;
bool check()
{
    for(int i=0;i<n;i++)
    {
        int l=(i==0?n-1:i-1),r=(i==n-1?0:i+1);
        if(b[i]<b[l]&&b[i]<b[r]);
        else if(b[i]>b[l]&&b[i]>b[r]);
        else return false;
    }
    return true;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        if(n%2==0)
        {
            for(int i=0;i<n/2;i++) b[i*2]=a[i];
            for(int i=n/2;i<n;i++) b[(i-n/2)*2+1]=a[i];
        }
        else 
        {
            int now=0;
            for(int i=0;i<n;i++) {b[now]=a[i]; now=(now+2)%n;}
        }
        if(!check()) {puts("NO"); continue;}
        puts("YES");
        for(int i=0;i<n;i++) printf("%d%c",b[i],i==n-1?'\n':' ');
    }

    return 0;
}