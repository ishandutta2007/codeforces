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
int cur,level[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        level[1]=1;
        cur=1;
        printf("%d\n",1);
        for(int i=2;i<=n;i++)
        {
            if(a[i]==1)
            {
                cur++;
                level[cur]=1;
            }
            else
            {
                while(a[i]!=level[cur]+1)
                {
                    cur--;
                    assert(cur);
                }
                level[cur]++;
            }
            printf("%d",level[1]);
            for(int i=2;i<=cur;i++) printf(".%d",level[i]);
            puts("");
        }
    }
    return 0;
}