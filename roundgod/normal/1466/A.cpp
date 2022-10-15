#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,x[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        set<int> s; s.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&x[i]);
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                s.insert(x[j]-x[i]);
        printf("%d\n",(int)s.size());
    }
    return 0;
}