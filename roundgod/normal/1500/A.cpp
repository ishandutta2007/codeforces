#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 5000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<P> save[MAXM];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int s=a[i]+a[j];
            for(auto p:save[s])
            {
                if(p.F!=i&&p.S!=i&&p.F!=j&&p.S!=j)
                {
                    puts("YES");
                    printf("%d %d %d %d\n",i,j,p.F,p.S);
                    return 0;
                }
            }
            if(save[s].size()<2) save[s].push_back(P(i,j)); 
        }
    puts("NO");
    return 0;
}