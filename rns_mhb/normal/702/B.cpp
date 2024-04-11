#include <bits/stdc++.h>
using namespace std;

#define N 100005

typedef long long ll;
int n;
int a[N];
map<int, int> cnt;
ll ans;

int main() {
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        for (int j = 0; j < 32; j ++) {
            ans += cnt[(1<<j)-a[i]];
        }
        cnt[a[i]] ++;
    }
    printf("%I64d\n", ans);
    return 0;
}