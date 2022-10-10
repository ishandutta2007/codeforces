#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, mn = 1e9, live = 0;
    cin >> n;
    vector<int> powers;
    for(int i = 0; i < n; i++) {
        int p;
        cin >> p;
        powers.push_back(p);
    }
    for(int i = n - 1; i >= 0; i--) {
        if(i < mn)
            live++;
        mn = min(mn, max(0, i - powers[i]));
    }
    cout << live << endl;
}