#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (1 << 18) + 50;

int n, x;
int a[N], psum[N];

int main() {
    cin >> n >> x;
    if(x >= (1 << n)) {
        cout << (1 << n) - 1 << endl;
        for(int i = 1; i < (1 << n); i++) psum[i] = i;
        for(int i = 1; i < (1 << n); i++) a[i] = psum[i] ^ psum[i-1], cout << a[i] << " ";
    }
    else {
        cout << (1 << (n - 1)) - 1 << endl;
        int b;
        for(b = 0; b < n; b++) if((x >> b) & 1) break;
        int cur = 1;
        for(int i = 1; i < (1 << (n - 1)); i++) {
            while((cur >> b) & 1) cur++;
            psum[i] = cur++;
        }
        for(int i = 1; i < (1 << (n - 1)); i++) a[i] = psum[i] ^ psum[i-1], cout << a[i] << " ";
    }
}