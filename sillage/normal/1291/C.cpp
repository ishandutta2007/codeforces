#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int a[3510];
int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d%d%d",&n,&m,&k);
        for (int i=1; i<=n; i++) scanf("%d",&a[i]);
        int res=n-m+1;
        if (k>=m) k=m-1;
        int ans=0;
        for (int i=0; i<=k; i++){
            int mn=1e9+10;
            for (int j=i+1; j<=i+n-k-res+1; j++){
                if (max(a[j],a[j+res-1])<mn) mn=max(a[j],a[j+res-1]);
            }
            if (mn>ans) ans=mn;
        }
        printf("%d\n",ans);
    }
    return 0;
}