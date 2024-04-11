#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> clx;
    vector<int> cly;
    clx.push_back(0);
    cly.push_back(2);
    int tx = -2;
    for (int i = 0; i <= n; ++i) {
        tx += 2;
        int cx = tx;
        int dy = (i % 2) * 2 - 1;
        int cy = 2 + dy;
        clx.push_back(cx);
        cly.push_back(cy);
        cy += dy;
        clx.push_back(cx);
        cly.push_back(cy);
        ++cx;
        clx.push_back(cx);
        cly.push_back(cy);
        ++cx;
        clx.push_back(cx);
        cly.push_back(cy);
        cy -= dy;
        clx.push_back(cx);
        cly.push_back(cy);
        cy -= dy;
        clx.push_back(cx);
        cly.push_back(cy);
        --cx;
        clx.push_back(cx);
        cly.push_back(cy);
    }
    
    cout << clx.size() << "\n";
    for (int i = 0; i < clx.size(); ++i) {
        cout << clx[i] << " " << cly[i] << "\n";
    }
    
    return 0;
}