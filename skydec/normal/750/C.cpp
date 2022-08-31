#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
int main(){
    int n;scanf("%d",&n);
    int l=-(1e9);
    int r=(1e9);
    int now=0;
    while(n--){
        int x,v;scanf("%d%d",&x,&v);
        if(v==1)l=max(1900-now,l);
        else r=min(r,1899-now);
        now+=x;
    }    
    if(l>r)puts("Impossible");
    else if(r>100000000)puts("Infinity");
    else printf("%d\n",now+r);
    return 0;
}