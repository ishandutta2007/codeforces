#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int l = 1, r = n * 2000 + n - 1;
    while (l < r) {
        int mid = l + r >> 1;
        cout << "? " << mid << endl;
        int h;
        cin >> h;
        if (h == 0 || h > 1) l = mid + 1; else r = mid;
    }
    int S = l;
    for (int i = 2; i <= n; i++) {
        cout << "? " << S / i << endl;
        int h;
        cin >> h;
        if (h == 0) break;
        if (S / i * h < S) S = S / i * h;
    }
    cout << "! " << S << endl;

}