#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, a[102];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n/2;i++) scanf("%d",&a[i]);
    int ans1=0,ans2=0;
    sort(a+1,a+1+n/2);
    for(int i=1;i<=n/2;i++) {
        ans1 += abs(a[i]-(2*i-1));
        ans2 += abs(a[i]-(2*i));
    }
    printf("%d\n", min(ans1,ans2));
}