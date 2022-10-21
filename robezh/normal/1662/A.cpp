#include <bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=15;
int a[N],n,T;
int main() {
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,10)a[i]=0;
        rep(i,n){
            int x,y;scanf("%d%d",&x,&y);
            a[y]=max(a[y],x);
        }
        int sum=0,flag=1;
        rep(i,10)sum+=a[i],flag&=(a[i]!=0);
        if(!flag)puts("MOREPROBLEMS");
        else printf("%d\n",sum);
    }

}