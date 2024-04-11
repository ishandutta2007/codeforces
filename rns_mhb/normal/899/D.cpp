#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int k = (int) log10(n<<1);
    int ans = 0;
    int l = 1;
    for (int i = 0; i < k; i ++) l *= 10;
    int a = (n<<1) / l;
    for (int t = 1; t <= a; t ++) {
        int m = l * t - 1;
        ans += (m - 1) / 2 - max(1, m - n) + 1;
    }
    cout<<ans;
    return 0;
}