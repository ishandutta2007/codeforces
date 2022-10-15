#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]&1)
        {
            if(cnt) a[i]=(a[i]+1)/2;
            else a[i]=(a[i]-1)/2;
            cnt^=1;
        }
        else a[i]=a[i]/2;
    }
    for(int i=1;i<=n;i++) printf("%d\n",a[i]);
    return 0;
}