#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

#define pb push_back

int a[200100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    string a, b[5];
    cin >> a >> b[0] >> b[1] >> b[2] >> b[3] >> b[4];
    bool ok = false;
    forn (i, 5) {
        if (a[0] == b[i][0] || a[1] == b[i][1])
            ok = true;
    }
    cout << (ok ? "YES" : "NO") << endl;
}