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
int t,n,m,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        if(m<n) {puts("No"); continue;}
        else if(n%2==0&&m%2==1) {puts("No"); continue;}
        puts("Yes");
        if(n==1) printf("%d\n",m);
        else if(n%2==1)
        {
            for(int i=1;i<=n-1;i++) printf("%d ",1);
            printf("%d\n",m-(n-1));
        }
        else 
        {
            for(int i=1;i<=n-2;i++) printf("%d ",1);
            printf("%d %d\n",(m-(n-2))/2,(m-(n-2))/2);
        }
    }
    return 0;
}