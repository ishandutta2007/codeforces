#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h, ret = 0;
    cin >> n >> h;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        ret += a > h ? 2 : 1;
    }
    cout << ret << endl;
    
    return 0;
}