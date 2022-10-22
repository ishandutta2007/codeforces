#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1000 + 13;
const int K = 17;
const int M = 998244353;
const int LOGN = 20;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
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

int pw[K + 1][N];
int res[K + 1][1 << K];
int ans[1 << K];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt = 0;
    for(char c : s)
        cnt += (c == '?');

    for(int k = 1; k <= 17; k++) {
        pw[k][0] = 1;
        for(int i = 1; i <= n; i++) {
            pw[k][i] = mul(pw[k][i - 1], k);
        }

        for(int i = 0; i < n; i++) {
            int mask = 0, /*res = 0,*/ cur = 1, qr = 0;
            for(int j = 0; i + j < n && i - j >= 0; j++) {
                qr += (s[i - j] == '?');
                if(j != 0)
                    qr += (s[i + j] == '?');
                if(s[i - j] == '?') {
                    if(s[i + j] == '?') {
                        cur = mul(cur, k);
                    } else {
                        int x = (s[i + j] - 'a');
                        mask |= (1 << x);
                    }
                } else {
                    if(s[i + j] == '?') {
                        int x = (s[i - j] - 'a');
                        mask |= (1 << x);
                    } else if(s[i - j] == s[i + j]){

                    } else {
                        cur = 0;
                    }
                }

//                cout << k << ' ' <<  i << ' ' << j << ' ' << mask << ' ' << cur << endl;

//                res[k][mask] = sum(res[k][mask], mul(cur, pow2(k, cnt - qr)));
                res[k][mask] = sum(res[k][mask], mul(cur, pw[k][cnt - qr]));
            }
        }

//        for(int mask = 0; mask < 4; mask++)
//            cout << "mask = " << mask << ' ' << "res = " << res[k][mask] << endl;


        for(int i = 0; i < n - 1; i++) {
            int mask = 0, cur = 1, qr = 0;
            for(int j = 0; i - j >= 0 && i + j + 1 < n; j++) {
                qr += (s[i - j] == '?');
                qr += (s[i + j + 1] == '?');
                if(s[i - j] == '?') {
                    if(s[i + j + 1] == '?') {
                        cur = mul(cur, k);
                    } else {
                        int x = (s[i + j + 1] - 'a');
                        mask |= (1 << x);
                    }
                } else {
                    if(s[i + j + 1] == '?') {
                        int x = (s[i - j] - 'a');
                        mask |= (1 << x);
                    } else if(s[i - j] == s[i + j + 1]){

                    } else {
                        cur = 0;
                    }
                }

                res[k][mask] = sum(res[k][mask], mul(cur, pw[k][cnt - qr]));
            }
        }

//        for(int mask = 0; mask < 4; mask++)
//            cout << "mask = " << mask << ' ' << "res = " << res[k][mask] << endl;
    }

//    for(int i = 1; i <= 2; i++) {
//        cout << i << " : ";
//        for(int mask = 0; mask < (1 << 2); mask++)
//            cout << mask << ' ' << res[i][mask] << endl;
//    }

    for(int mask = 0; mask < (1 << K); mask++) {
        int k = __builtin_popcount(mask);
        ans[mask] = res[k][0];
        for(int msk = mask; msk > 0; msk = ((msk - 1) & mask)) {
            ans[mask] = sum(ans[mask], res[k][msk]);
        }
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        string t;
        cin >> t;

        int mask = 0;
        for(char c : t)
            mask |= (1 << int(c - 'a'));

        cout << ans[mask] << '\n';
    }
}