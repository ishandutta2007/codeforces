#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
//const int A = 1e6 + 13;
const int N = 1e6 + 13;
const int B = 400;
const int LOGN = 20;

mt19937 rnd(7476);

int a[N];
li f[N];

li get(int x) {
//    cout << "get " << x << endl;
    if(x == 0)
        return 0ll;
    for(int i = 0; ; i++)
        if(x >= f[i] && x < f[i + 1])
            return get(x - f[i]) | (1ll << i);
}

void solve() {
    int n;
    cin >> n;

    vector<int> cnt(60, 0);
    bool ans = true;
    li sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        sum += a[i];
    }

//    cout << sum << endl;

    li cur = 0;
    int j = -1;
    for(int i = 0; ; i++) {
        cur += f[i];
//        cout << cur << endl;
        if(cur >= sum) {
            if(cur != sum) {
                cout << "NO\n";
                return;
            }

            j = i;
            break;
        }
    }

//    cout << j << endl;

    multiset<int> ms(a, a + n);
    int prv = -1;
    while(j >= 0) {
        if(ms.empty()) {
            ans = false;
            break;
        }

        int x = *ms.rbegin();
        ms.erase(prev(ms.end()));

        if(x < f[j]) {
            ans = false;
            break;
        }

        x -= f[j];

        if(prv > 0)
            ms.insert(prv);

        prv = x;
        j--;
    }

    ans &= ms.empty();

    cout << (ans ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    f[0] = f[1] = 1;
    for(int i = 2; i < 60; i++) {
        f[i] = f[i - 1] + f[i - 2];
        //cout << f[i] << endl;
    }

//    cout << f[59] << endl;

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}