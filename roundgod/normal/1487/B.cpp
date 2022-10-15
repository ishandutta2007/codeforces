#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        if(n%2==0) printf("%d\n",(k%n==0?n:k%n));
        else 
        {
            int need=(n-1)/2;
            k+=(k-1)/need;
            printf("%d\n",(k%n==0?n:k%n));
        }
    }
}