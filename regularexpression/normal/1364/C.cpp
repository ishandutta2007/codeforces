#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int inf = 1e6;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i!=n; ++i)
        cin >> a[i];
    vector<int> b(n, inf), c;
    int d=0;
    for (int i=0; i!=n; ++i) {
        c.push_back(i);
        while (d<a[i]) {
            b[c.back()] = d++;
            c.pop_back();
        }
    }
    for (int i=0; i<n; ++i)
        cout << (i==0?"":" ") << b[i];
    return 0;
}