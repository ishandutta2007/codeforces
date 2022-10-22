//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define int li

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
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();

    int fir = 0;
    while(fir < n && s[fir] == 'a')
        fir++;

    if(fir == n) {
        s.back() = 'z';
        cout << s << endl;
    } else {
        while(fir < n && s[fir] != 'a') {
            s[fir++]--;
        }

        cout << s << endl;
    }
}