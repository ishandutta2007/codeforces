#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;

int n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    if(n % 2 == 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    int cur = 0;
    for(int i = 1; i <= n; i++) {

        if(i % 2 == 1) a[i] = 2 * i - 1, a[i + n] = 2 * i;
        else a[i + n] = 2 * i - 1, a[i] = 2 * i;
    }
    for(int i = 1; i <= 2 * n; i++) cout << a[i] << " ";
}