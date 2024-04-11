#include<bits/stdc++.h>
#define maxn 505050

using namespace std;
typedef long long ll;
ll a[maxn],b[maxn],ans,d,e,n,h,f,g;
char s[maxn];

int main(){
    cin >> n;
    for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    scanf("%s",s+1);
    for (int i=1;i<=n;i++){
        if (s[i]=='G') b[i]=0;
        else if (s[i]=='W') b[i]=1;
        else b[i]=2;
    }
    int pos=n+1; d=0;
    for (int i=1;i<=n;i++) if (b[i]==1) {pos=i; break;}
    for (int i=1;i<pos;){
        e=0;
        while (i<pos&&b[i]==0) d+=a[i],ans+=a[i]*5,i++;
        while (i<pos&&b[i]==2) e+=a[i],ans+=a[i],i++;
        if (d<e) ans+=(e-d)*5,d=0; else d-=e;
    }
    for (int i=pos;i<=n;){
        e=0;
        while (i<=n&&b[i]<2) {
            if (b[i]==0) {
                ll res=d+g+a[i];
                g=min(f,g+a[i]); d=res-g;
                ans+=a[i]*5;
            }
            else f+=a[i],ans+=a[i]*3;
            i++;
        }
        while (i<=n&&b[i]==2) e+=a[i],ans+=a[i],i++;
        ll res=d+g;
        if (res+f<e) ans+=(e-res-f)*3,d=0,g=0,f=0;
        else if (f>e) f-=e; else {
            res-=e-f,f=0;
            g=min(res,min(f,g)); d=res-g;
        }
        res=d+g; g=min(g,f); d=res-g;
    }
    ans-=d*2;
    if (f>g){
        ans-=f*3+g*5;
        ans+=(f+g)*2;
    } else {
        ans-=(f+g)*2;
    }
    cout << ans << endl;
}