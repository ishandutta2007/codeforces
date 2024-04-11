#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        bool f=true;
        for(int i=2;i<=n;i++) if(a[i]!=a[i-1]) f=false;
        if(!f) puts("1"); else printf("%d\n",n); 
    }
    return 0;
}