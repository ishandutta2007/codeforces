#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
int main()
{
    scanf("%d",&n);
    printf("%d\n",4+3*n);
    printf("%d %d\n",0,0);
    printf("%d %d\n",0,1);
    printf("%d %d\n",1,0);
    for(int i=1;i<=n;i++)
    {
        printf("%d %d\n",i,i);
        printf("%d %d\n",i+1,i);
        printf("%d %d\n",i,i+1);
    }
    printf("%d %d\n",n+1,n+1);
    return 0;
}