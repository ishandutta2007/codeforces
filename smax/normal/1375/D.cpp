#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int a[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        multiset<int> st;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            st.insert(a[i]);
        }
        vector<int> ret;
        while (true) {
            int idx = -1, mex = (st.find(0) != st.end() ? INT_MAX : 0);
            for (int i=0; i<n; i++) {
                if (i > 0 && a[i] < a[i-1])
                    idx = i;
                if (st.find(a[i] + 1) == st.end())
                    mex = min(mex, a[i] + 1);
            }
            if (idx == -1)
                break;

//            DEBUG(mex)
//            for (int i=0; i<n; i++)
//                cerr << a[i] << " \n"[i==n-1];
//            int p;
//            cin >> p;

            if (mex == n) {
                pair<int, int> best(INT_MAX, -1);
                for (int i=0; i<n; i++) {
                    if (a[i] != i) {
                        best = make_pair(a[i], i);
                        break;
                    }
                }
//                for (int i=0; i<n; i++)
//                    cerr << a[i] << " \n"[i==n-1];
//                DEBUG(mex, best.second)
                ret.push_back(best.second + 1);
                st.erase(st.find(best.first));
                st.insert(mex);
                a[best.second] = mex;
            } else {
                ret.push_back(mex + 1);
                st.erase(st.find(a[mex]));
                st.insert(mex);
                a[mex] = mex;
            }

//            for (int i=0; i<n; i++)
//                if (i == idx || a[i] > mex) {
//                    ret.push_back(i + 1);
//                    st.erase(st.find(a[i]));
//                    st.insert(mex);
//                    a[i] = mex;
//                    break;
//                }
        }

        cout << ret.size() << "\n";
        for (int x : ret)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}