#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fuckcjb
#define y0 fuckyzc
#define x1 fucklyk
#define y1 fuckjsb
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1e6+5;
int l,r,n;char s[N];
int x0,y0,x1,y1;
int main(){
    scanf("%d",&n);
    l=1,r=2e9-3;
    x0=1,y0=1;
    x1=1e9-1,y1=1e9-1;
    rep(i,n){
        int mid=(0ll+l+r)/2;
        int x,y;
        if(mid<=1e9-1)printf("%d %d\n",x=mid,y=1);
        else printf("%d %d\n",x=1e9-1,y=mid-1e9+1+1);
        fflush(stdout);
        scanf("%s",s+1);
        if(s[1]=='b')l=mid,x0=x,y0=y;else r=mid,x1=x,y1=y;
    }
    printf("%d %d %d %d\n",x0-1,y0+1,x1+1,y1-1);
    return 0;
}