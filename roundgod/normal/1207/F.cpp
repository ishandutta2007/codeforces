#include<bits/stdc++.h>
#define MAXN 500005
#define INF 100000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int q;
int a[MAXN];
int res[805][805];
int main()
{
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int type,x,y;
        scanf("%d%d%d",&type,&x,&y);
        if(type==1)
        {
            a[x]+=y;
            for(int j=1;j<=800;j++) res[j][x%j]+=y;
        }
        else
        {
            if(x<=800) printf("%d\n",res[x][y]);
            else
            {
                int ans=0;
                for(int j=y;j<=500000;j+=x) ans+=a[j];
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}