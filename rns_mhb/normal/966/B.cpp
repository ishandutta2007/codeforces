#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    typedef pair <int, int> pii;
    vector <pii> c(n);
    for(int i = 0; i < n; i ++) cin >> c[i].first, c[i].second = i+1;
    sort(c.begin(), c.end(), greater <pii> ());
    for(int i = 1; i < n; i ++) {
        int mn = c[i].first;
        int k1 = (x+mn-1) / mn;
        int k2 = i+1 - k1;
        if(k2 > 0 && c[k2-1].first >= (y+k2-1)/k2) {
            cout << "Yes" << endl;
            cout << k1 << ' ' << k2 << endl;
            for(int j = k2; j <= i; j ++) cout << c[j].second << ' ';
            cout << endl;
            for(int j = 0; j < k2; j ++) cout << c[j].second << ' ';
            cout << endl;
            return 0;
        }
        k1 = (y+mn-1) / mn;
        k2 = i+1-k1;
        if(k2 > 0 && c[k2-1].first >= (x+k2-1)/k2) {
            cout << "Yes" << endl;
            cout << k2 << ' ' << k1 << endl;
            for(int j = 0; j < k2; j ++) cout << c[j].second << ' ';
            cout << endl;
            for(int j = k2; j <= i; j ++) cout << c[j].second << ' ';
            cout << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}