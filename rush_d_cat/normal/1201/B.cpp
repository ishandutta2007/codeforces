#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1000000 + 10;
typedef long long LL;
int n,a[N];
int main() {
    scanf("%d",&n);
    LL sum=0,mx=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i]; mx=max(mx,(LL)a[i]);
    }
    if(sum%2) return !printf("NO\n");
    printf("%s\n", sum>=2*mx ? "YES" : "NO");
}