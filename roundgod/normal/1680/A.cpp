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
int t,l1,l2,r1,r2;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(l2>r1||l1>r2) printf("%d\n",l1+l2); else printf("%d\n",max(l1,l2));
    }
    return 0;
}