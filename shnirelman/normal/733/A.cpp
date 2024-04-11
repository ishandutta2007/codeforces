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
const int N = 2e5 + 13;
const int M = 1e9 + 9;
const ld eps = 1e-6;
const int K = 103;

/*
3 1
1 0 0
*/


signed main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    string s;
    cin >> s;

    s = "A" + s + "A";

    set<char> v = {'A', 'E', 'I', 'O', 'U', 'Y'};

    int lst = 0;
    int ans = 1;
    for(int i = 1; i < s.size(); i++) {
        if(v.count(s[i])) {
            ans = max(ans, i - lst);
            lst = i;
        }
    }

    cout << ans << endl;
}