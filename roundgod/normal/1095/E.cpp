#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],b[MAXN],c[MAXN];
char s[MAXN];

int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) 
        a[i]=a[i-1]+((s[i]=='(')?1:-1);
    b[0]=a[0]; 
    for(int i=1;i<=n;i++) 
        b[i]=min(b[i-1],a[i]);
    c[n]=a[n]; 
    for(int i=n-1;i>=0;i--) 
        c[i]=min(c[i+1],a[i]);
    if(a[n]==2)
    {
        for(int i=1;i<=n;i++)
            if(a[i]-a[i-1]==1&&b[i-1]>=0&&c[i]>=2) 
                k++;
    }
    else if(a[n]==-2)
    {
        for(int i=1;i<=n;i++)
            if(a[i]-a[i-1]==-1&&b[i-1]>=0&&c[i]>=-2) 
                k++;
    }
    printf("%d\n",k);
    return 0;
}