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
const int N = 3e6 + 13;
const int M = 1e9 + 7;
const ld eps = 1e-6;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int cnt[N];
li add[N];

pii qr[N];
li res[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        cnt[x]++;
    }

    for(int i = 0; i < N; i++) if(cnt[i]) {
        li cur = 0;
        for(int j = 1; j * i < N && j < i; j++) {
//            if(j != i)
//                cur += cnt[i] * 1ll * cnt[j];
//            else
//                cur += cnt[i] * 1ll * (cnt[i] - 1);

            add[i * j] += cnt[i] * 1ll * cnt[j];
//            add[i * (j + 1)] -= cur;
        }
        if(i * 1ll * i < N)
            add[i * i] += cnt[i] * 1ll * (cnt[i] - 1) / 2;
    }

    li cur = 0;
    for(int i = 0; i < N; i++) {
        cur += add[i];
        res[i] = cur;
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; i++) {
        int p;
        cin >> p;

        cout << n * 1ll * (n - 1) - res[p - 1] * 2 << '\n';
    }
}