#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, min, max, ret = 0;
    cin >> n >> min;
    max = min;
    for (int i=1; i<n; i++) {
        int a;
        cin >> a;
        if (a > max) {
            max = a;
            ret++;
        } else if (a < min) {
            min = a;
            ret++;
        }
    }
    cout << ret << endl;
    
    return 0;
}