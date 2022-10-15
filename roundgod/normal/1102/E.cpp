#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],sum[MAXN];
map<int,int> fst,last;
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(fst.find(a[i])==fst.end()) fst[a[i]]=i;
        last[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        sum[fst[a[i]]+1]++; sum[last[a[i]]+1]--;
    }
    int cnt=0;
    for(int i=1;i<=n;i++) 
    {
        sum[i]+=sum[i-1];
        if(!sum[i]) cnt++;
    }
    printf("%d\n",pow_mod(2,cnt-1));
    return 0;
}