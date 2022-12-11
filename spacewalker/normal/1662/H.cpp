#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for (int i = (x); i < (y); i++)
typedef pair<int,int> ii;



unordered_set<int> fact(int n) {
    unordered_set<int> facs;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            facs.insert(i);
            facs.insert(n / i);
        }
    }
    return facs;
}

void solve(int w, int l) {
    vector<ii> pairs = {{w, l - 2}, {w - 1, l - 1}, {w - 2, l}};
    set<int> tot;
    for (auto &[fr,sc] : pairs) {
        unordered_set<int> s = fact(fr);
        unordered_set<int> s2 = fact(sc);
        for (auto &i : s) {
            if (s2.count(i)) tot.insert(i);
        }
    }
    vector<tuple<int,int,int>> tup = {{w, l - 1, w - 2}, {w - 1, l, l - 2}};
     for (auto &[fr,sc,tr] : tup) {
        unordered_set<int> s = fact(fr);
        unordered_set<int> s2 = fact(sc);
        unordered_set<int> s3 = fact(tr);
        for (auto &i : s) {
            if (s2.count(i) && s3.count(i)) tot.insert(i);
        }
    }
    cout << (int)(tot.size()) << ' ';
    for (auto &i : tot) cout << i << ' ';
    cout << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        int w,l; cin >> w >> l;
        solve(w,l);
    }
}