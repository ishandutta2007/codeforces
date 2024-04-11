#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first 
#define S second
#define x1 daksida 
#define y1 daskdsia
#define x2 doakdos
#define y2 dakoda
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int d=INF;
        int id=-1;
        for(int i=1;i<=n-1;i++) 
        {
            if(a[i+1]-a[i]<d)
            {
                d=a[i+1]-a[i];
                id=i;
            }
        } 
        printf("%d ",a[id]);
        for(int i=id+2;i<=n;i++) printf("%d ",a[i]);
        for(int i=1;i<=id-1;i++) printf("%d ",a[i]);
        printf("%d\n",a[id+1]);
    }
    return 0;
}