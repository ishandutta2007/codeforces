#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x,a[MAXN];
int cnt[MAXN];
int main()
{
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(x==1) {puts("Yes"); return 0;}
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=x) continue;
        cnt[a[i]]++;
        int now=a[i];
        while(now<x&&cnt[now]==now+1)
        {
            cnt[now+1]++;
            cnt[now]=0;
            now++;
        }
    }
    bool f=true;
    for(int i=1;i<=x-1;i++) if(cnt[i]) f=false;
    if(f) puts("Yes"); else puts("No");
    return 0;
}