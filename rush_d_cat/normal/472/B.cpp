#include <iostream>
#include <algorithm>
using namespace std;
const int N = 20002;
int n,k,a[N];
int main() {
    scanf("%d%d",&n,&k);
    int ans = 0;
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i-=k) {
        ans = ans + 2*(a[i]-1);
    }
    cout << ans << endl;
}