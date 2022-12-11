#include <bits/stdc++.h>
using namespace std;

const string S = "RGB";

void solve() {
    int b, w;
    int x = 2;
    int y = 2;
    cin >> b >> w;
    if (w > b) {
        swap(b, w);
        x++;
    }
    
    if (b > 3 * w + 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    
    for (int i = 0; i < w; i++) cout << x + i * 2 << " " << y << "\n";
    for (int i = 0; i <= w; i++) {
        if (b > 0) {
            b--;
            cout << x + i * 2 - 1 << " " << y << "\n";
        }
    }
    for (int yy = y - 1; yy <= y + 1; yy += 2)
    for (int xx = 0; xx < w; xx++)
    if (b > 0) {
        b--;
        cout << x + xx * 2 << " " << yy << "\n";
    }
}

int main() {
    int t = 0;
    cin >> t;
    while (t--) solve();
    return 0;   
}