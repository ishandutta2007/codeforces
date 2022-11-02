#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k = 0;
    cin >> n;
    for(int i = 1, x; i <= n; i ++) {
        cin >> x;
        if(x & 1) k ++;
    }
    cout << min(k, n-k) << endl;
}