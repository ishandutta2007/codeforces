#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
int check(int id)
{
    if(id>=2&&id<n&&a[id]>a[id-1]&&a[id]>a[id+1]) return 1;
    if(id>=2&&id<n&&a[id]<a[id-1]&&a[id]<a[id+1]) return 1;
    return 0;
}
int get_res(int id)
{
    int res=check(id);
    if(id>1) res+=check(id-1);
    if(id<n) res+=check(id+1);
    return res;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans=0;
        for(int i=1;i<=n;i++) ans+=check(i);
        int res=0;
        for(int i=1;i<=n;i++)
        {
            int tmp=a[i],val=get_res(i);
            if(i>1)
            {
                a[i]=a[i-1];
                res=min(res,get_res(i)-val);
                a[i]=tmp;
            }
            if(i<n)
            {
                a[i]=a[i+1];
                res=min(res,get_res(i)-val);
                a[i]=tmp;
            }
        }
        printf("%d\n",ans+res);
    }
}