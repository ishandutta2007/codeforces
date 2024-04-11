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

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int n;
int t[N];

void add(int i, int x) {
    for(; i < n; i |= (i + 1))
        t[i] += x;
}

int get(int i) {
    int res = 0;
    for(; i >= 0; i = (i & (i + 1)) - 1)
        res += t[i];
    return res;
}

int a[N], b[N], wha[N], whb[N];
int c[N], p[N];

void solve() {
    int s;
    cin >> n >> s;

    for(int i = 0; i < n; i++) {
        t[i] = 0;
        whb[i] = -1;
        c[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        wha[a[i]] = i;
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];

        if(b[i] != -1) {
            b[i]--;
            whb[b[i]] = i;
        }
    }

    for(int i = 0; i < n; i++) {
        if(b[i] == -1) {
            add(a[i], 1);
//            c[a[i]]++;
        }
    }

//    for(int i = 0; i < n; i++) {
//        p[i + 1] = p[i] + c[i];
//    }

//    for(int i = 0; i < n; i++)
//        cout << c[i] << ' ';
//    cout << endl;
//    for(int i = 0; i <= n; i++)
//        cout << p[i] << ' ';
//    cout << endl;

    int ans = 1;
    int cnt = 0;
    for(int i = 0; i < s; i++) {
        cnt += (b[wha[i]] == -1);
    }
    for(int i = 0; i < n; i++) {
        if(i + s < n && b[wha[i + s]] == -1)
            cnt++;

        if(whb[i] == -1) {
            ans = mul(ans, cnt);
            cnt--;
//            if(b[wha[i]] != -1)
//                cnt++;
//            ans = mul(ans, p[min(i + s + 1, n)] - p[i]);
        } else {
            int j = whb[i], k = wha[i];
            if(i + s >= a[j]) {
                if(b[k] == -1) {
                    add(a[j], 1);
//                    cnt++;
                }
                swap(wha[a[j]], wha[i]);
                swap(a[j], a[k]);
            } else {
                ans = 0;
                break;
            }
        }

//        cout << i << ' ' << ans << ' ' << cnt << endl;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}