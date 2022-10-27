#include <iostream>
using namespace std;
typedef long long LL;
const int N = 100000+10;
int n,m,l;
LL a[N];
int main() {
    scanf("%d%d%d",&n,&m,&l);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int sz=0;
    for(int i=1;i<=n;i++) {
        if(a[i]>l && a[i-1]<=l) sz++;
    }
    while(m--) {
        int op,p,d; scanf("%d",&op);
        if(op==0) {
            printf("%d\n", sz);
        } else {
            scanf("%d%d",&p,&d);
            if(a[p]<=l) {
                if(a[p]+d<=l) {
                    a[p]+=d;
                } else {
                    a[p]+=d;
                    if(a[p-1]>l && a[p+1]>l) sz --;
                    else if(a[p-1]<=l && a[p+1]<=l) sz ++;
                }
            } else {
                a[p] += d;
            }
        }
    }
}