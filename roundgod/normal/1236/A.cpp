#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,a,b,c;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        int ans=0;
        ans=min(b,c/2); b-=ans;
        ans+=min(a,b/2);
        printf("%d\n",3*ans);
    }
    return 0;
}