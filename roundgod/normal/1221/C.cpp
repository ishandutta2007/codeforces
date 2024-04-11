#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
int main()
{
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int c,m,x;
        scanf("%d%d%d",&c,&m,&x);
        int sum=c+m+x;
        printf("%d\n",min(min(c,m),sum/3));
    }
    return 0;
}