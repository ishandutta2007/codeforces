#include <iostream>
using namespace std;
int n,m;
int ans;
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int l,r;scanf("%d%d",&l,&r);
        int d=r-l+1;
        if(d%2==0) ans+=(d/2)*(d/2);
        else ans+=(d/2)*(d/2+1);
    }
    for(int i=1;i<=n;i++){
        printf("%d", i%2?1:0);
    }
}