#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, k, w1[101010], w2[101010];
const int MAXN = 101010;
const int MINN = 1;

map<int, int> f1, f2; // just in case
vector <int> a, b; // we're gonna use this one

int main () {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; a.push_back(x);
    }
    for (int i = 0; i < m; ++i) {
        int x; cin >> x; b.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int x = 0;
    int p1 = 0, p2 = 0;  // justin case
    while (a.size() && b.size()) {if (a.back() > b.back()) {a.pop_back(); x++;} else {b.pop_back(); x--;} if (x > 0) {cout << "YES\n"; return 0;}} if (x + (int) a.size() > 0) cout << "YES\n"; else cout << "NO\n"; return 0;
{}}