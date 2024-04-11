#include <iostream>
#include <algorithm>
using namespace std;
const int N = 102;
int n,a[N],b[N];

int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    int L=1,R=n;
    for(int i=1;i<=n;i++) {
        if(i%2==1) b[L++]=a[i];
        else b[R--]=a[i];
    }
    for(int i=1;i<=n;i++)
        printf("%d ", b[i]);
}