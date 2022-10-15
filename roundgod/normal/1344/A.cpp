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
int cnt[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) cnt[i]=0;
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++) cnt[((i+a[i%n])%n+n)%n]++;
        bool f=true;
        for(int i=0;i<n;i++) if(cnt[i]!=1) f=false;
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}