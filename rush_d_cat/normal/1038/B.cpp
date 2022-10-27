#include <iostream>
using namespace std;
int n;
int main() {
    cin >> n;
    if (n<=2) {
        return !printf("No\n");
    }
    int bu;
    if (n%2==0) {
        bu = n/2;
    } else {
        bu = (n+1)/2;
    }
    printf("Yes\n");
    printf("1 %d\n", bu);
    printf("%d", n-1);
    for(int i=1;i<=n;i++) if(bu!=i) printf(" %d", i); printf("\n");
}