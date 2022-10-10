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

int l[2005], r[2005];
vector<int> st[2005], nd[2005];

int intersect(int l1, int r1, int l2, int r2) {
    return max(min(r1, r2) - max(l1, l2) + 1, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i<m; i++) {
        cin >> l[i] >> r[i];
        l[i]--, r[i]--;
        st[l[i]].push_back(i);
        nd[r[i]].push_back(i);
    }

    int ret = 0;
    for (int l1=0; l1<=n-k; l1++) {
        // brute force position of first author interval
        int r1 = l1 + k - 1, cur = 0;
        vector<vector<int>> transfer(n + 1);
        for (int i=0; i<m; i++) {
            // binary search for when first author becomes more optimal than second
            // this step can be probably done in O(1) with some math but I'm lazy
            cur += intersect(l1, r1, l[i], r[i]);
            int lo = l1, hi = n;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (intersect(l1, r1, l[i], r[i]) > intersect(mid, mid + k - 1, l[i], r[i]))
                    hi = mid;
                else
                    lo = mid + 1;
            }
            transfer[lo].push_back(i);
        }
        int in = 0, out = 0;
        vector<bool> isIn(m), isOut(m);
        for (int i=0; i<m; i++) {
            if (l1 < l[i] && l[i] <= r1) {
                isIn[i] = true;
                in++;
            }
            if (l1 <= r[i] && r[i] <= r1) {
                isOut[i] = true;
                out++;
            }
        }
        for (int i : transfer[l1]) {
            if (isIn[i]) {
                in--;
                isIn[i] = false;
            }
            if (isOut[i]) {
                out--;
                isOut[i] = false;
            }
        }
        ret = max(ret, cur);
        for (int l2=l1+1; l2<=n-k; l2++) {
            // sweep second author interval
            int r2 = l2 + k - 1;
            for (int i : st[r2]) {
                in++;
                isIn[i] = true;
            }
            assert(in >= 0 && out >= 0);
            cur += in - out;
            for (int i : transfer[l2]) {
                cur += intersect(l1, r1, l[i], r[i]) - intersect(l2, r2, l[i], r[i]);
                if (isIn[i]) {
                    in--;
                    isIn[i] = false;
                }
                if (isOut[i]) {
                    out--;
                    isOut[i] = false;
                }
            }
            for (int i : st[l2])
                if (isIn[i]) {
                    in--;
                    isIn[i] = false;
                }
            for (int i : nd[r2]) {
                out++;
                isOut[i] = true;
            }
            for (int i : nd[l2-1])
                if (isOut[i]) {
                    out--;
                    isOut[i] = false;
                }
            ret = max(ret, cur);
        }
    }
    cout << ret << "\n";

    return 0;
}