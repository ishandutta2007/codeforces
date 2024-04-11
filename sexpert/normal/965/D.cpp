#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int a[MAXN], b[MAXN];

int main() {
    int n, w;
    cin >> n >> w;
    for(int i = 1; i <= n - 1; i++)
        cin >> a[i];
    a[n] = INT_MAX;
    b[0] = INT_MAX;

    int l = 0, r = 1;
    while(r <= n) {
        if(a[r] == 0)
            r++;
        while(l < r - w)
            l++;
        while(l < r - 1 && b[l] == 0)
            l++;
        if(b[l] > 0) {
            int d = min(b[l], a[r]);
            b[l] -= d;
            a[r] -= d;
            b[r] += d;
        }
        else
            r++;
        if(a[r] == 0)
            r++;
    }
    cout << b[n] << '\n';
}