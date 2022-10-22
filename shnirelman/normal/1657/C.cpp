#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
//const int M = 1e9 + 7;
const int M = 998244353;
const int N = 2e5 + 13;
const int LOGN = 30;

/*

*/

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int c = 0, r = n;
    for(int i = 0; i < n; ) {
        if(i == n - 1)
            break;

        if(s[i] == '(' || s[i + 1] == ')') {
            c++;
            r -= 2;
            i += 2;
            continue;
        }

        int j = i + 1;
        while(j < n && s[j] == '(')
            j++;

//        if(s[j] == '(') {
        if(j < n) {
            i = j + 1;
            c++;
            r = n - i;
        } else {
            break;
        }
    }

    cout << c << ' ' << r << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}