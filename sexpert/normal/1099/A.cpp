#include <bits/stdc++.h>
using namespace std;

int main() {
    int w, h, w1, d1, w2, d2;
    cin >> w >> h >> w1 >> d1 >> w2 >> d2;
    while(h > 0) {
        w += h;
        if(h == d1)
            w -= w1;
        if(h == d2)
            w -= w2;
        w = max(w, 0);
        h--;
    }
    cout << w << endl;
}