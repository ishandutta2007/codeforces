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
int n,x,y,a[MAXN];
int main()
{
    scanf("%d%d%d",&n,&x,&y);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(x>y) {printf("%d\n",n); return 0;}
    int ans=0;
    for(int i=1;i<=n;i++) if(a[i]<=x) ans++;
    printf("%d\n",(ans+1)/2);
    return 0;
}