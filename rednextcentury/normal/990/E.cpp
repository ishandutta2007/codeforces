#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool a[2000000];
int last[2000000];
int c[2000000];
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=m;i++){
        int x;
        scanf("%d",&x);
        a[x]=1;
    }
    for (int i=1;i<=k;i++) {
        scanf("%d",&c[i]);
    }
    int lst=-4000000;
    for (int i=0;i<=n;i++) {
        if (a[i]==0)lst=i;
        last[i]=lst;
    }
    ll ret=1e18;
    for (int i=1;i<=k;i++){
        int v = 0;
        ll cost = 0;
        while(v<n) {

            if (last[v]+i<=v)break;
            v=last[v]+i;
            cost++;
        }
        if (v>=n)

            ret=min(ret,cost*c[i]);
    }
    if (ret>=1e17)ret=-1;
    printf("%lld\n",ret);
}