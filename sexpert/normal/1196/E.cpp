#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int b, w, off = 0;
    cin >> b >> w;
    if(b > 3*w + 1 || w > 3*b + 1) {
        cout << "NO\n";
        return;
    }
    if(b < w) {
        off = 1;
        swap(w, b);
    }
    cout << "YES\n";
    for(int i = 1; i <= w; i++)
        cout << "2 " << 2*i + off << '\n';
    for(int i = 1; i <= w; i++)
        cout << "2 " << 2*i + 1 + off << '\n';
    int rem = b - w;
    for(int i = 1; i <= w; i++) {
        if(rem == 0)
            break;
        cout << "1 " << 2*i + off << '\n';
        rem--;
    }
    for(int i = 1; i <= w; i++) {
        if(rem == 0)
            break;
        cout << "3 " << 2*i + off << '\n';
        rem--;
    }
    if(rem)
        cout << "2 " << 1 + off << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}