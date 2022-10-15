#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int x=0;
        while(n)
        {
            x=max(x,n%10);
            n/=10;
        }
        printf("%d\n",x);
    }
    return 0;
}