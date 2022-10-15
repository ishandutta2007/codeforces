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
        int pre=k-(n-k);
        for(int i=1;i<pre;i++) printf("%d ",i);
        for(int i=k;i>=pre;i--) printf("%d ",i);
        puts("");
    }
    return 0;
}