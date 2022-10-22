#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

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

    if(k % 2)
        return mul(pw, n);
    else
        return pw;
}
/*
*/
int a[N];
set<int> st;
set<pii> seg;

int calc() {
    if(st.size() <= 2)
        return 0;

    return (*st.rbegin() - *st.begin() - seg.rbegin()->f);
}

void solve() {
    int n, q;
    cin >> n >> q;


    for(int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }

    sort(a, a + n);


    for(int i = 0; i < n - 1; i++) {
        seg.insert({a[i + 1] - a[i], a[i]});
    }

    cout << calc() << '\n';

    for(int i = 0; i < q; i++) {
        int t, x;
        cin >> t >> x;

        if(t == 0) {
            auto itl = st.lower_bound(x);
            auto itr = itl;

            itr++;

            if(itr != st.end()) {
                seg.erase({*itr - x, x});
            }

            if(itl != st.begin()) {
                itl--;
                seg.erase({x - *itl, *itl});
                if(itr != st.end()) {
                    seg.insert({*itr - *itl, *itl});
                }
            }

            st.erase(x);
        } else  {


            if(!st.empty()) {
                auto itr = st.upper_bound(x);
                auto itl = itr;

                if(itr != st.end() && itl != st.begin()) {
                    itl--;
                    seg.erase({*itr - *itl, *itl});
                }

                if(itr != st.end()) {
                    seg.insert({*itr - x, x});
                }

                if(itr != st.begin()) {
                    itl = itr;
                    itl--;
                    seg.insert({x - *itl, *itl});
                }
            }

            st.insert(x);
        }

        cout << calc() << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}