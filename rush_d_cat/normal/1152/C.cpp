#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
LL a,b,ans,bst;
void upd(LL g) {
    LL aa = (a/g)*g; if(aa<a) aa+=g;
    LL bb = (b/g)*g; if(bb<b) bb+=g;

    if(aa/g*bb < ans) {
        ans = aa/g*bb;
        bst = aa-a;
    }
}
int main() {
    ans=4e18;
    cin>>a>>b;
    if(a==b){
        return !printf("0\n");
    }
    if(a>b) swap(a,b);
    for(LL g=1;g*g<=(b-a);g++) {
        if((b-a)%g==0) {
            upd(g);
            upd((b-a)/g);
        }
    }
    printf("%lld\n", bst);
}