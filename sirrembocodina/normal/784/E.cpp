#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define fs first
#define sc second
#define mp make_pair

int main() {
    ios::sync_with_stdio(0);
    long long ans = 1;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << int(((a ^ b) && (c || d)) ^ ((b && c) || (a ^ d))) << endl;
    return 0;
}