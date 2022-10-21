#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;

int n, a[N];
ll smax[N], smin[N];
ll dpmax[N], dpmin[N];
ll psum[N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        psum[i] = a[i] + (i == 0 ? 0 : psum[i-1]);
    }

    smax[n-1] = -psum[n-1];
    smin[n-1] = psum[n-1];
    for(int i = n - 2; i >= 0; i--) {
        dpmax[i] = smin[i+1];
        dpmin[i] = smax[i+1];
        smin[i] = max(smin[i+1], dpmin[i] + psum[i]);
        smax[i] = min(smax[i+1], dpmax[i] - psum[i]);
    }
    cout << dpmax[0] << endl;
}