#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int N=100000+10;
int n;
int a[N];

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d\n", n+1);
    printf("2 %d 1\n",n);
    printf("1 %d 1000000\n", n);
    for(int i=1;i<n;i++) {
        printf("2 %d %d\n", i,1000000-i);
    }
}