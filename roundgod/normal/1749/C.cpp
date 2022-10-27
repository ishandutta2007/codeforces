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
int t,n,a[MAXN];
bool check(int x)
{
    multiset<int> ms;
    for(int i=1;i<=n;i++) ms.insert(a[i]);
    for(int i=1;i<=x;i++)
    {
        while(ms.size()&&(*(--ms.end())>x-i+1)) ms.erase(--ms.end());
        if(!ms.size()) return false;
        ms.erase(--ms.end());
        if(ms.size()) ms.erase(ms.begin());
    }
    return true;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=n;i>=0;i--) if(check(i)) {printf("%d\n",i); break;}
    }
    return 0;
}