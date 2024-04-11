#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, neg = 0, cnt1 = 0, cnt2 = 0;
    long long ret = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (neg % 2 == 0)
            cnt1++;
        else
            cnt2++;
        neg += a < 0;
        if (neg % 2 == 0)
            ret += cnt1;
        else
            ret += cnt2;
    }
    cout << (long long) n * (n + 1) / 2 - ret << " " << ret << "\n";

    return 0;
}