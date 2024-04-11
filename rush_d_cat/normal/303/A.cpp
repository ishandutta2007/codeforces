#include <iostream>
using namespace std;
int n;
int main() {
    cin>>n;
    if(n&1) {
        for(int i=0;i<n;i++) printf("%d ",i); printf("\n");
        for(int i=0;i<n;i++) printf("%d ",i); printf("\n");
        for(int i=0;i<n;i++) printf("%d ",(i+i)%n); printf("\n");
    } else {
        printf("-1\n");
    }
}