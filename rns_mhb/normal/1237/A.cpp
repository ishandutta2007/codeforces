#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> b(n), a(n);
    for(int i = 0; i < n; i ++) cin >> b[i];
    int c = 0;
    for(int i = 0; i < n; i ++) {
        if(b[i] >= 0) a[i] = b[i] / 2;
        else a[i] = (b[i]-1) / 2;
        c -= a[i];
    }
    for(int i = 0; i < n; i ++) if(b[i] & 1) {
        a[i] ++;
        c --;
        if(c == 0) break;
    }
    for(int i = 0; i < n; i ++) cout << a[i] << endl;
}