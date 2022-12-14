#include<bits/stdc++.h>
using namespace std;
#define ll long long
int best[1000000];
int id[1000000];
int a[100];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) {
        for (int j=0;j<m;j++) {
            scanf("%d",&a[j]);
        }
        for (int mask=0;mask<(1<<m);mask++){
            int mn = 1e9;
            for (int j=0;j<m;j++) {
                if ((1<<j)&mask)mn=min(mn,a[j]);
            }
            if (mn>=best[mask]) {
                best[mask] = max(best[mask], mn);
                id[mask]=i;
            }
        }
    }
    int ret=0;
    int A=0,B=0;
    for (int mask=0;mask<(1<<m);mask++){
        if (min(best[mask],best[(1<<m)-1-mask])>=ret){
            A = id[mask], B=id[(1<<m)-1-mask];
            ret=max(ret, min(best[mask],best[(1<<m)-1-mask]));
        }
    }

    cout<<A<<' '<<B<<endl;
}