#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int q,n,k,a[MAXN];
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if(x>2048) continue; else sum+=x;
        }
        if(sum>=2048) puts("YES"); else puts("NO");
    }
    return 0;
}