#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        printf("%d\n",3*n);
        for(int i=1;i<=n;i+=2)
        {
            printf("%d %d %d\n",1,i,i+1);
            printf("%d %d %d\n",2,i,i+1);
            printf("%d %d %d\n",1,i,i+1);
            printf("%d %d %d\n",2,i,i+1);
            printf("%d %d %d\n",1,i,i+1);
            printf("%d %d %d\n",2,i,i+1);
        }
    }
}