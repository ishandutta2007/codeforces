#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

#define pb push_back

int a[200100];
int b[200100];
int p[200100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n;
    cin >> n;
    forn (i, n) {
        cin >> a[i];
        --a[i];
        p[a[i]] = n - i - 1;
    }
    forn (i, n) {
        cin >> b[i];
        --b[i];
        b[i] = p[b[i]];
    }
    int ans = 0;
    int mx = -1;
    for (int i = n - 1; i >= 0; --i) {
//    	cerr << b[i] + 1 << " ";
        if (b[i] < mx) {
        	ans++;
        }
        mx = max(mx, b[i]);
    }
//    cerr << endl;
    cout << ans << endl;
}