#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) ((int)(x).size())

bool ok(int x, int y, int z) {
    return (x<=y && y<=z) || (x>=y && y>=z);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v;
        while (n--) {
            int a;
            cin >> a;
            while (sz(v)>=2 && ok(a, v.back(), v[sz(v)-2]))
                v.pop_back();
            v.push_back(a);
        }
        cout << sz(v) << '\n';
        for (int i=0; i!=sz(v); ++i)
            cout << (i==0?"":" ") << v[i];
        cout << '\n';
    }
    return 0;
}