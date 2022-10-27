#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100000 + 10;
int T,n,a[N];
int main() {
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+n);
        int ans=min(a[n-1]-1, n-2);
        printf("%d\n", ans);
    }
}