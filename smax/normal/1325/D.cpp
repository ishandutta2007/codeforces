#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

bool leaking[100] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // u - xor, v - sum
    long long u, v;
    cin >> u >> v;

    if (u == 0 && v == 0) {
        cout << "0\n";
        return 0;
    }

    if (u > v) {
        cout << "-1\n";
        return 0;
    }

    vector<long long> ret{u};
    long long rem = v - u;
    for (int i=59; i>0; i--) {
        if (rem == 0)
            break;

        if (rem & (1LL << i)) {
            int cnt = 0;
            for (long long &n : ret)
                if (!(n & (1LL << (i - 1)))) {
                    n |= 1LL << (i - 1);
                    cnt++;
                    if (cnt == 2)
                        break;
                }
            for (int j=0; j<2-cnt; j++)
                ret.push_back(1LL << (i - 1));
            rem -= 1LL << i;
        }
    }

    if (rem > 0) {
        cout << "-1\n";
        return 0;
    }
    cout << ret.size() << "\n";
    for (long long i : ret)
        cout << i << " ";
    cout << "\n";

//    int maxI = 63 - __builtin_clzll(u);
//    vector<long long> ret;
//    for (int i=0; i<60; i++) {
//        int uBit = u & (1LL << i), vBit = v & (1LL << i);
//        // 0 means need even # of 1's, 1 means need odd #
//        int parity = ((uBit > 0) + leaking[i]) % 2;    // sum parity right now
//        DEBUG(parity)
//        if (parity != (vBit > 0)) { // make it leak to next bit instead
//            if (i == 0) {
//                cout << "-1\n";
//                return 0;
//            }
//            int p = i;
//            while (p < 100 && leaking[p]) {
//                leaking[p++] = false;
//            }
//            if (p >= 100) {
//                cout << "-1\n";
//                return 0;
//            }
//            leaking[p] = true;
//            int cnt = 0;
//            for (long long &n : ret) {
//                if (!(n & (1LL << (i - 1)))) {
//                    n |= 1LL << (i - 1);
//                    cnt++;
//                    if (cnt == 2)
//                        break;
//                }
//            }
//            for (int j=0; j<2-cnt; j++)
//                ret.push_back(1LL << (i - 1));
//            parity = !parity;
//        }
//        // at this point, desired xor and sum parity match
//        // check current xor
//        bool odd = false;
//        for (long long n : ret)
//            if (n & (1 << i))
//                odd = !odd;
//        if (odd != parity) {   // add one bit
//            if (odd) {
//                int p = i + 1;
//                while (p < 100 && leaking[p])
//                    leaking[p++] = false;
//                if (p >= 100) {
//                    cout << "-1\n";
//                    return 0;
//                }
//                leaking[p] = true;
//            }
//            int cnt = 0;
//            for (long long &n : ret) {
//                if (!(n & (1LL << i))) {
//                    n |= 1LL << i;
//                    cnt++;
//                    if (cnt == 1)
//                        break;
//                }
//            }
//            for (int j=0; j<1-cnt; j++)
//                ret.push_back(1LL << i);
//        }
//        DEBUG(ret);
//    }
//
//    long long xx = 0, ss = 0;
//    for (long long n : ret) {
//        xx ^= n;
//        ss += n;
//    }
//    //assert(xx == u && ss == v);
//
//    cout << ret.size() << "\n";
//    for (long long i : ret)
//        cout << i << " ";
//    cout << "\n";

    return 0;
}