#include <iostream>

using namespace std;

const int N = 1e6 + 34;

int n, x, mx;
int a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
        if (a[x] > a[mx])
            mx = x;
    }
    cout << mx;
    return 0;
}