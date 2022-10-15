#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN],b[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        bool has1=false,hasm1=false,f=true;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=b[i])
            {
                if(a[i]>b[i]&&!hasm1) f=false;
                if(a[i]<b[i]&&!has1) f=false;
            }
            if(b[i]==-1||a[i]==-1) hasm1=true;
            if(b[i]==1||a[i]==1) has1=true;
        }
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}