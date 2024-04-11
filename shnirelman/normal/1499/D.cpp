#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e7 + 13;
const int LOGN = 20;
const int A = 27;

int dd[N];
int cnt[N];

void solve() {
    int c, d, x;
    cin >> c >> d >> x;

    li ans = 0;
    for(int i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            for(int j = 0, g = i; j < 2 - (i * i == x); j++, g = x / i) {
                int abc = x / g + d;
                if(abc % c != 0) {
                    continue;
                }

                int ab = abc / c;

                ans += (1ll << cnt[ab]);
//                set<int> st;
//                while(ab > 1) {
//                    st.insert(dd[ab]);
//                    ab /= dd[ab];
//                }
//
////                cout << g << ' ' << ab << ' ' << st.size() << endl;
//
//                ans += (1ll << st.size());
            }
        }
    }

    cout << ans << endl;
}

int main() {
    for(int i = 2; i < N; i++) {
        if(dd[i] == 0) {
            dd[i] = i;
            if(i * 1ll * i < N)
                for(int j = i * i; j < N; j += i)
                    dd[j] = i;
        }
    }

    cnt[1] = 0;
    for(int i = 2; i < N; i++) {
//            cout << i << endl;
        cnt[i] = cnt[i / dd[i]] + (i / dd[i] % dd[i] != 0);
    }

    int t;
    cin >> t;

    while(t--)
        solve();
}