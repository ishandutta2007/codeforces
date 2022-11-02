#include<bits/stdc++.h>
using namespace std;

bool good(int x) {
    int y = 0;
    while(x) {
        int d = x % 10;
        if(y >> d & 1) return 0;
        y ^= 1 << d;
        x /= 10;
    }
    return 1;
}

int main() {
    int x, y;
    cin >> x >> y;
    for(; x <= y; x ++) if(good(x)) {
        cout << x << endl;
        return 0;
    }
    puts("-1");
}