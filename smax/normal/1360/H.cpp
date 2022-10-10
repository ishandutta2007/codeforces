#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

set<long long> st;

void up(long long &x) {
    x++;
    while (st.count(x))
        x++;
}

void down(long long &x) {
    x--;
    while (st.count(x))
        x--;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        st.clear();
        long long mid = 0;
        for (int j=0; j<m-1; j++)
            mid |= 1LL << j;

        long long sz = 1 << m;
        for (int i=0; i<n; i++) {
            string s;
            cin >> s;

            long long a = 0;
            for (int j=0; j<m; j++) {
                if (s[s.length()-j-1] == '1')
                    a |= 1LL << j;
            }
            st.insert(a);
            if (a == mid) {
                if (sz % 2)
                    down(mid);
                else
                    up(mid);
            }
            else if (a < mid) {
                if (sz % 2 == 0)
                    up(mid);
            } else {
                if (sz % 2)
                    down(mid);
            }
            sz--;
//            DEBUG(mid)
        }


        for (int j=m-1; j>=0; j--)
            cout << ((mid >> j) & 1);
        cout << "\n";
    }

    return 0;
}