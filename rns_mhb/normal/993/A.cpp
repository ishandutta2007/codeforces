#include<bits/stdc++.h>
using namespace std;

int main() {
    int l, r, d, u, L, R, D, U;
    l = d = L = D = 1e9;
    r = u = R = U = -1e9;
    for(int i = 0; i < 8; i ++) {
        int x;
        cin >> x;
        if(i & 1) {
            d = min(d, x);
            u = max(u, x);
        }
        else {
            l = min(l, x);
            r = max(r, x);
        }
    }
    for(int i = 0; i < 8; i ++) {
        int x;
        cin >> x;
        if(i & 1) {
            D = min(D, x);
            U = max(U, x);
        }
        else {
            L = min(L, x);
            R = max(R, x);
        }
    }
    int mx = (L+R)/2, my = (D+U)/2;
    int dist = R - mx;
    for(int x = -100; x <= 100; x ++) for(int y = -100; y <= 100; y ++) {
        if(l <= x && x <= r && d <= y && y <= u && abs(mx-x)+abs(my-y) <= dist) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}