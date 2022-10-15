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
int b,k,a[MAXN];
int main()
{
    scanf("%d%d",&b,&k);
    for(int i=0;i<k;i++) scanf("%d",&a[i]);
    int now=0;
    if(b&1)
    {
    for(int i=k-1;i>=0;i--) now^=(a[i]&1);
    }
    else now^=(a[k-1]&1);
    if(now&1) puts("odd"); else puts("even");
    return 0;
}