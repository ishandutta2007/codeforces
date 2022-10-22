//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const li INF = 1e18 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 8;

mt19937 rnd(0);

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int i;
    for(i = 0; i < n; i++) {
        if(s[i] != '?')
            break;
    }

    char cur;
    if(i == n || s[i] == 'R')
        cur = 'B';
    else
        cur = 'R';

    for(int j = i - 1; j >= 0; j--) {
        s[j] = cur;
        if(cur == 'R')
            cur = 'B';
        else
            cur = 'R';
    }

    for(int j = i + 1; j < n; j++) {
        if(s[j] == '?') {
            s[j] = (s[j - 1] == 'R' ? 'B' : 'R');
        }
    }

    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}