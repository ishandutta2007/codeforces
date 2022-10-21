#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50, B = 31;

int n;
int a[N];

struct Basis {
    int sz = 0;
    int bas[B];

    bool add(int x) {
        if(x == 0) return false;
        for(int i = 0; i < sz; i++) {
            if((x ^ bas[i]) < x) x ^= bas[i];
            if(x == 0) return false;
        }
        bas[sz++] = x;
        for(int i = sz - 2; i >= 0; i--) {
            if(bas[i] < bas[i+1]) swap(bas[i], bas[i+1]);
        }
        return true;
    }



}basis;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], a[i] ^= a[i-1];
    if(a[n] == 0) return cout << "-1" << endl, 0;
    basis.add(a[n]);
    for(int i = 1; i <= n-1; i++) {
        basis.add(a[i]);
    }
    cout << basis.sz << endl;
}