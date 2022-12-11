#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 34;

int n, k;
int a[N];
int mn = 1e9;
int pos = -1, h0, cur;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        h0 = a[i] - i * k;
        if (h0 <= 0)
            continue;
        cur = 0;
        for (int j = 0; j < n; j++)
            if (a[j] != h0 + j * k)
                cur++;
        if (cur < mn) {
            mn = cur;
            pos = i;
        }
    }
    cout << mn << "\n";
    h0 = a[pos] - pos * k;
    for (int i = 0; i < n; i++) {
        if (a[i] < h0 + i * k)
            cout << "+ " << i + 1 << " " << h0 + i * k - a[i] << "\n";
        if (a[i] > h0 + i * k)
            cout << "- " << i + 1 << " " << a[i] - i * k - h0 << "\n";
    }


    return 0;
}