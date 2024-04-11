//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2000 + 13;
const int M = 1e9 + 7;
const ld eps = 1e-6;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set<char> good = {'A', 'H', 'I', 'M', 'O', 'o', 'T', 'U', 'V', 'v', 'W', 'w', 'X', 'x', 'Y'};

    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        int j = s.size() - i - 1;

        if(s[i] == s[j] && good.count(s[i]) ||
           s[i] == 'b' && s[j] == 'd' || s[i] == 'd' && s[j] == 'b' ||
           s[i] == 'p' && s[j] == 'q' || s[i] == 'q' && s[j] == 'p') {

           } else {
            cout << "NIE" << endl;
            return 0;
           }
    }

    cout << "TAK" << endl;
}