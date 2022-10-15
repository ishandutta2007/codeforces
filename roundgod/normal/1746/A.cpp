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
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        int s=0;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); s+=a[i];}
        if(s) puts("YES"); else puts("NO");
    }
    return 0;
}