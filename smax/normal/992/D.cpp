#include <bits/stdc++.h>
using namespace std;

int a[200000], nxt[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++)
        cin >> a[i];

    int pos = -1;
    for (int i=0; i<n; i++) {
        nxt[i] = pos;
        if (a[i] > 1)
            pos = i;
    }

    long long ret = 0;
    for (int i=0; i<n; i++) {
        long long sum = 0, product = 1;
        for (int j=i; j!=-1; j=nxt[j]) {
            if (a[j] > LLONG_MAX / product)
                break;
            sum += a[j];
            product *= a[j];
            if (product % k == 0)
                ret += (sum <= product / k && product / k <= sum + j - nxt[j] - 1);
            sum += j - nxt[j] - 1;
        }
    }

    cout << ret << "\n";

    return 0;
}