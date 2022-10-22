#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 998244353;
const int N = 2e5 + 13;
const int LOGN = 20;

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

int inv(int n) {
    return pow2(n, M - 2);
}

mt19937 rnd(0);

/*
*/

void solve() {
    li n, m, k;
    cin >> n >> m >> k;

    vector<int> a(k);
    vector<int> b(k, 0), c(k, 0);
    for(int i = 0; i < k; i++) {
        cin >> a[i];
        if(a[i] >= n * 2) {
            b[i] = a[i] / n;
        }

        if(a[i] >= m * 2) {
            c[i] = a[i] / m;
        }
    }

    bool ans = false;

    for(int it = 0; it < 2; it++) {
//        sort(b.rbegin(), b.rend());
        li sum1 = 0, sum2 = 0;
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < k; i++)
            if(b[i] > 2) {
                cnt1++;
                sum1 += b[i];
            } else if(b[i] == 2) {
                cnt2++;
                sum2 += b[i];
            }

//        cout << "it = " << it << endl;
//        cout << sum1 << ' ' << sum2 << ' ' << cnt1 << ' ' << cnt2 << endl;

        if(cnt1 == 0) {
            if(m % 2 == 0)
                ans |= (sum2 >= m);
        } else {
            li m1 = m - sum1;
            if(m1 <= 0)
                ans = true;
            else {
//                if(m1 % 2 != 0)
//                    m1++;

                ans |= (sum2 >= (m1 + 1) / 2 * 2);
            }
        }



        swap(b, c);
        swap(n, m);
    }
//    cout << (x >= m && (m % 2 == 0 || flx) || y >= n && (n % 2 == 0 || fly) ? "Yes" : "No") << endl;
    cout << (ans ? "Yes" : "No") << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}