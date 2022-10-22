#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using matr = vector<vi>;

const int INF = 1e9 + 13;
const li INF64 = 4e18 + 13;
//const int M = 1e9 + 7;
//const int M = 998244353;
const int N = 1e5 + 13;
const int LOGN = 30;

int M;

int sum(int a, int b) {
    a += b;

    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

mt19937 rnd(45567);

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(')
            cnt0++;
        else if(s[i] == ')')
            cnt1++;
        else
            cnt2++;
    }

    int x0 = 0, x1 = 0;
    for(int i = 0; i <= cnt2; i++) {
        if(cnt0 + i == cnt1 + cnt2 - i) {
            x0 = i;
            x1 = cnt2 - i;
            break;
        }
    }

    if(x0 == 0 || x1 == 0) {
        cout << "YES\n";
        return;
    }

    string s1 = s;
    bool fl = false;
    for(int i = 0; i < n; i++) {
        if(s[i] != '?')
            continue;
        if(x0 == 1 && !fl || x0 == 0) {
            s1[i] = ')';
            fl = true;
            x1--;
        } else {
            s1[i] = '(';
            x0--;
        }
    }

    int cur = 0;

    for(int i = 0; i < n; i++) {
        if(s1[i] == '(')
            cur++;
        else
            cur--;

        if(cur < 0) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}