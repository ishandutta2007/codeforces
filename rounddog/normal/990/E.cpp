#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#define maxn 2000001
using namespace std;
typedef long long ll;
ll n,a[maxn],pre[maxn],k,d,m,c[maxn],w,x[maxn],res;
bool f[maxn];

int main(){
    cin >> n >> m >> k;
    for (int i=0;i<m;i++){
        int r; scanf("%d",&r);
        f[r]=true;
    }
    for (int i=1;i<=k;i++) scanf("%d",&c[i]);
    if (f[0]){
        printf("-1\n");
        return 0;
    }
    for (int i=1;i<=n;i++) pre[i]=(f[i-1])?pre[i-1]:i-1;
    for (int i=1;i<=n+n;i++) x[i]=(f[i])?x[i-1]:i;
    w=0;
    for (int i=1;i<=n;i++) {
        w=max(w,i-pre[i]);
    }
    if (w>k){
        printf("-1\n");
        return 0;
    }
    ll ans=1e18;
    for (int i=w;i<=k;i++){
        res=0;
        d=0; while (d<n) d=x[d+i],res+=c[i];
        ans=min(ans,res);
    }
    cout << ans << endl;
}