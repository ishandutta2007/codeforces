#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

const int N = 2e5 + 13;

int a[N], b[N];

set<int> st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = 0;
        st.insert(i);
    }

    int q;
    cin >> q;

    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int i, x;
            cin >> i >> x;

            i--;

            while(x > 0) {
                int d = min(x, a[i] - b[i]);

//                cout << i << ' ' << x << endl;

                x -= d;
                b[i] += d;

                if(b[i] == a[i])
                    st.erase(i);

                auto it = st.upper_bound(i);

                if(it == st.end())
                    break;

                i = *it;
            }
        } else {
            int i;
            cin >> i;

            cout << b[i - 1] << '\n';
        }
    }

}