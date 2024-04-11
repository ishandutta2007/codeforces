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
int T,l,r;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&l,&r);
        if(l*2>r) puts("-1"); else printf("%d %d\n",l,l*2);
    }
    return 0;
}