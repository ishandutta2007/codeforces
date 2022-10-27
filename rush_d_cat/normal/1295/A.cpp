#include <iostream>
using namespace std;
int t,n;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        if(n%2==1) {
            printf("7"); n-=3;
            for(int i=1;i<=n/2;i++) printf("1");
            printf("\n");
        } else {
            for(int i=1;i<=n/2;i++) printf("1");
            printf("\n");
        }
    }
}