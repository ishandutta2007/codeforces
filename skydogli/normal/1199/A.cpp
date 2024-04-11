#include<bits/stdc++.h>
using namespace std;
int n,xx,yy,a[1000005];
int main(){
    scanf("%d%d%d",&n,&xx,&yy);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;++i){
        bool t=0;
        for(int j=max(1,i-xx);j<=min(i+yy,n);++j)
            if(a[i]>a[j]){t=1;break;}
        if(!t){printf("%d",i);return 0;}
    }
    return 0;
}