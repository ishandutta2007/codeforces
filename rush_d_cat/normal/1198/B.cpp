#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N=200000+10;
int n,q;
int a[N],t[N];
int suf[N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);t[i]=0;
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++) {
        int op,p,x; scanf("%d",&op);
        if(op==1){
            scanf("%d%d",&p,&x);
            a[p]=x;t[p]=i;
        } else {
            scanf("%d",&x); suf[i]=x;
        }
    }
    for(int i=q-1;i>=0;i--){
        suf[i]=max(suf[i+1],suf[i]);
    }
    for(int i=1;i<=n;i++){
        printf("%d ", max(a[i],suf[t[i]]));
    }
}