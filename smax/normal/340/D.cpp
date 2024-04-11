#include <bits/stdc++.h>
using namespace std;

int n, bit[100001] = {};

int getMax(int index) {
    int ret = 0;
    while (index > 0) {
        ret = max(ret, bit[index]);
        index -= index & (-index);
    }
    return ret;
}

void update(int index, int val) {
    while (index <= n) {
        bit[index] = max(bit[index], val);
        index += index & (-index);
    }
}

int a[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    int ret = 0;
    for (int i=0; i<n; i++) {
        int mx = getMax(a[i]);
        ret = max(ret, mx + 1);
        update(a[i], mx + 1);
    }

    cout << ret << "\n";

    return 0;
}