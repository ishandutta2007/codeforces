#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, a[500000], cnt[500000];
    long long sum = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 3 != 0)
        cout << "0\n";
    else {
        sum /= 3;
        long long sum2 = a[n-1];
        cnt[n-1] = a[n-1] == sum;
        for (int i=n-2; i>=2; i--) {
            sum2 += a[i];
            cnt[i] = cnt[i+1] + (sum2 == sum);
        }

        long long ret = 0;
        sum2 = 0;
        for (int i=0; i<n-2; i++) {
            sum2 += a[i];
            if (sum2 == sum)
                ret += cnt[i+2];
        }
        cout << ret << "\n";
    }

    return 0;
}