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
const int N = 1e6 + 13;
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

    string s;
    cin >> s;

    int n = s.size();

    int ca = 0, cb = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '.') {
            cb = n - i - 1;
            break;
        }
        ca++;
    }

    int fir = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != '0' && s[i] != '.') {
            fir = i;
            break;
        }
    }

    int lst = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != '0' && s[i] != '.') {
            lst = i;
        }
    }

    string a(1, s[fir]);
    if(lst != fir) {
        a += '.';
        for(int i = fir + 1; i <= lst; i++) {
            if(s[i] != '.')
                a += s[i];
        }
    }

    int b = (fir < ca ? ca - fir - 1 : ca - fir);
    cout << a;
    if(b != 0)
        cout << "E" << b;
    cout << endl;
}