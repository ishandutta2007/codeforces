#include <iostream>
using namespace std;
int t;

int main() {
    scanf("%d", &t);
    while(t--) {
        int b,p,f; scanf("%d%d%d",&b,&p,&f); b/=2;
        int h,c; scanf("%d%d",&h,&c);
        if(h<c) {
            swap(h,c); swap(p,f);
        }
        int ans = h * min(b,p) + c * max(0, min(f, b - min(b,p)));
        printf("%d\n", ans);
    }
}