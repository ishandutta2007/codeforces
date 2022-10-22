#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000000009;

vector<int> v;
vector<int> siz;

void ass(int x, int l, int r, int c) {
    if (r == l + 1) {
        v[c] = 1;
        siz[c] = 1;
        return;
    }
    int mid = (l + r) / 2;
    if (x < mid) {
        ass(x, l, mid, c * 2 + 1);
    } else {
        ass(x, mid, r, c * 2 + 2);
    }
    siz[c] = siz[c * 2 + 1] + siz[c * 2 + 2];
}

void rem(int x, int l, int r, int c) {
    if (r == l + 1) {
        v[c] = 0;
        siz[c] = 0;
        return;
    }
    int mid = (l + r) / 2;
    if (x < siz[c * 2 + 1]) {
        rem(x, l, mid, c * 2 + 1);
    } else {
        rem(x - siz[c * 2 + 1], mid, r, c * 2 + 2);
    }
    siz[c] = siz[c * 2 + 1] + siz[c * 2 + 2];
}

int att(int x, int l, int r, int c) {
    if (r == l + 1) {
        return v[c];
    }
    int mid = (l + r) / 2;
    if (x < mid) {
        return att(x, l, mid, c * 2 + 1);
    }
    return att(x, mid, r, c * 2 + 2);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    
    v.assign(n * 4 + 5, 0);
    siz.assign(n * 8 + 10, 0);
    
    vector<int> ans;
    for (int q = 0; q < n; ++q) {
        int z;
        cin >> z;
        if (z >= 0) {
            ass(ans.size(), 0, n, 0);
            ans.push_back(z);
            continue;
        }
        
        vector<int> cura;
        for (int i = 0; i < m && a[i] <= siz[0]; ++i) {
            cura.push_back(a[i]);
        }
        reverse(cura.begin(), cura.end());
        for (int i = 0; i < cura.size(); ++i) {
            rem(cura[i] - 1, 0, n, 0);
        }
    }
    
    string s = "";
    for (int i = 0; i < ans.size(); ++i) {
        if (att(i, 0, n, 0) == 1) {
            s += ('0' + ans[i]);
        }
    }
    if (s == "") {
        cout << "Poor stack!\n";
    } else {
        cout << s << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    for (int qq = 0; qq < t; ++qq) {
       solve();
    }
   
    return 0;
}