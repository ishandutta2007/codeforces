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
int T,ang;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&ang);
        int g=__gcd(ang,180);
        int base=180/g;
        int l=0,r=100;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(180*(mid*base-2)>=ang*mid*base) r=mid; else l=mid;
        }
        printf("%d\n",r*base);
    }
    return 0;
}