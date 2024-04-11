#include<bits/stdc++.h>
using namespace std;
int a[200010];
void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a+1, a+1+n);
    long long ans1 = 1LL *a[1] * a[2] * a[n] * a[n-1] * a[n-2];
    long long ans0 = 1LL *a[n] * a[n-1] * a[n-2] * a[n-3] * a[n-4];
    long long ans2 = 1LL *a[1] * a[2] * a[3] * a[4] * a[n];
    long long ans3 = 1LL *a[1] * a[2] * a[3] * a[4] * a[5];
    long long ans4 = 1ll * a[1] * a[n] * a[n-1] * a[n-2] * a[n-3];
    long long ans5 = 1LL *a[1] * a[2] * a[3] * a[n] * a[n-1];
    printf("%lld\n", max(max(max(ans0, ans1), max(ans2, ans3)), max(ans4, ans5)));

}
int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        solve();
    }
}