//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vint = vector<int>;
using matr = vector<vint>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 3e5 + 13;
const int M = 1e9 + 9;
const ld eps = 1e-6;
const int K = 103;
const int LOGN = 22;
const int A = 52;


/*
*/

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    s += '_';
    n++;

    bool is = false;

    int cur = 0;

    int mx = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            mx = max(mx, cur);
            is = true;
            cur = 0;
        } else if(s[i] == ')') {
            is = false;
            if(cur > 0)
                cnt++;
            cur = 0;
        } else if(s[i] == '_') {
            if(is && cur > 0)
                cnt++;
            if(!is)
                mx = max(mx, cur);
            cur = 0;
        } else {
            cur++;
        }
    }

    cout << mx << ' ' << cnt << endl;
}