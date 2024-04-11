#include <bits/stdc++.h>

using namespace std;
using li = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    li s1 = 0, s2 = 0;
    for(auto a1 : a) {
        s1 += a1;
        s2 ^= a1;
    }

    cout << 2 << endl << s2 << ' ' << (s1 + s2) << endl;

    /*if(s1 == s2 * 2) {
        cout << 0 << endl << endl;
    } else if(s1 + 2 == s2 * 2) {
        cout << 2 << endl << 1 << ' ' << 1 << endl;
    } else if(s1 < s2 * 2) {
        vector<li> ans(0);
        if(s1 & 1) {
            ans.push_back(1);
            s1++;
            s2 ^= 1;
        }

        li b = (s2 * 2 - s1) / 2;

        ans.push_back(b);
        ans.push_back(b);

        cout<< ans.size() << endl;
        for(auto an : ans)
            cout << an << ' ';
        cout << endl;
    } else {

    }*/
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}