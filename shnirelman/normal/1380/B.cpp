#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

int a[N];
int p[N], s[N];

void solve() {
    string t;
    cin >> t;

    int n = t.size();

    int r = 0, s = 0, p = 0;
    for(int i = 0; i < n; i++) {
        if(t[i] == 'R')
            r++;
        else if(t[i] == 'S')
            s++;
        else
            p++;
    }

    char c;
    if(p >= max(s, r))
        c = 'S';
    else if(s >= max(p, r))
        c = 'R';
    else
        c = 'P';

    for(int i = 0; i < n; i++)
        cout << c;
    cout << endl;
}

int main() {
    int t = 1;
    cin >> t;

    while(t--)
        solve();
}