#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,a,b;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        if(__gcd(a,b)==1) puts("Finite"); else puts("Infinite");
    }
    return 0;
}