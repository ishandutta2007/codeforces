#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int a[300001];

main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    int ans = 1e9;
    for(int i=0;i<n/2;i++) ans = min(ans,a[n/2+i]-a[i]);
    printf("%d\n",ans);
}