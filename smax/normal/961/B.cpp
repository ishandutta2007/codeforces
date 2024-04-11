#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, ret = 0, kSum = 0, a[100000], t[100000];
    cin >> n >> k;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n; i++) {
        cin >> t[i];
        if (t[i] == 1)
            ret += a[i];
    }
    
    int ptr = k;
    for (int i=0; i<k; i++)
        if (t[i] == 0)
            kSum += a[i];
    int mx = kSum;
    while (ptr < n) {
        if (t[ptr] == 0)
            kSum += a[ptr];
        if (t[ptr-k] == 0)
            kSum -= a[ptr-k];
        mx = max(mx, kSum);
        ptr++;
    }
    
    cout << ret + mx << endl;
    
    return 0;
}