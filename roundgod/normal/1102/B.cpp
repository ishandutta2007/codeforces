#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],cnt[MAXN],col[MAXN];
unordered_set<int> s[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        cnt[a[i]]++; 
    }
    for(int i=1;i<=5000;i++) if(cnt[i]>k) {puts("NO"); return 0;}
    puts("YES");
    for(int i=1;i<=k;i++) 
    {
        col[i]=i;
        s[i].insert(a[i]);
    }
    for(int i=k+1;i<=n;i++)
    {
        for(int j=1;j<=k;j++) if(!s[j].count(a[i])) {col[i]=j; s[j].insert(a[i]); break;}
    }
    for(int i=1;i<=n;i++) printf("%d ",col[i]);
    return 0;
}