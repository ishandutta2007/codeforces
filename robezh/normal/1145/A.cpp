#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int n;
int a[N];

bool good(int l, int r) {
    for(int j = l + 1; j < r; j++) if(a[j] < a[j-1]) return false;
    return true;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 0;
    for(int i = 1; i <= n; i *= 2) {
        for(int j = 0; j < n; j += i) {
            if(good(j, j + i)) res = max(res, i);
        }
    }
    cout << res << endl;
}