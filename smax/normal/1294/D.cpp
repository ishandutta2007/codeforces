#include <bits/stdc++.h>
using namespace std;

long long mod[400000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q, x;
    cin >> q >> x;

    set<long long> mex;
    for (int i=0; i<x; i++) {
        mod[i] = i;
        mex.insert(i);
    }
    while (q--) {
        int y;
        cin >> y;
        mex.erase(mod[y%x]);
        mod[y%x] += x;
        mex.insert(mod[y%x]);
        cout << *mex.begin() << "\n";
    }

    return 0;
}