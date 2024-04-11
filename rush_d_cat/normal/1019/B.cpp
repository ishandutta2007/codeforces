#include <iostream>
#include <set>
using namespace std;
int n,val[100000+10];
int ask(int x) {
    int a,b;
    printf("? %d\n", x); fflush(stdout);
    scanf("%d",&a);
    printf("? %d\n", x+n/2); fflush(stdout);
    scanf("%d",&b);
    if (a==b) { 
        printf("! %d\n", x); fflush(stdout); exit(0); 
    }
    if ((a-b)%2!=0) {
        printf("! -1\n"); fflush(stdout); exit(0);
    }
    if (a-b>0) val[x]=1;
    if (a-b<0) val[x]=-1;
    if (a ==b) val[x]=0;
    return a - b;
}
int main() {
    scanf("%d", &n);
    int l=1,r=n/2;
    ask(l); ask(r);

    while(r-l>1) {
        int mid=(l+r)>>1;
        ask(mid);
        if (val[mid]*val[l]==-1) {
            r=mid;
        } else {
            l=mid;
        }
    } 
    printf("-1\n"); fflush(stdout);
}