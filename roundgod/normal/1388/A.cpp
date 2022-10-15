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
bool isprime[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d",&n);
       if(n<=30) puts("NO");
       else
       {
           puts("YES");
           if(n==36||n==40||n==44) printf("%d %d %d %d\n",6,10,15,n-31);
           else printf("%d %d %d %d\n",6,10,14,n-30);
       }
    }
    return 0;
}