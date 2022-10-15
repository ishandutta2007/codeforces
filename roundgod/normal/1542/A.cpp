#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int x=0,y=0;
        scanf("%d",&n);
        for(int i=1;i<=2*n;i++) 
        {
            scanf("%d",&a[i]);
            if(a[i]&1) x++; else y++;
        }
        if(x==n) puts("Yes"); else puts("No");
    }
    return 0;
}