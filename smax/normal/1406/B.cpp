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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> pos, neg;
        bool zero = false;
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            if (a > 0) pos.push_back(a);
            else if (a < 0) neg.push_back(a);
            else zero = true;
        }

        sort(pos.rbegin(), pos.rend());
        sort(neg.begin(), neg.end());
        long long ret = zero ? 0 : LLONG_MIN;
        // force positive number
        for (int p=1; p<=min(5, (int) pos.size()); p+=2) {
            if (5 - p > (int) neg.size())
                continue;
            long long prod = 1;
            for (int j=0; j<p; j++)
                prod *= pos[j];
            for (int j=0; j<5-p; j++)
                prod *= neg[j];
            ret = max(ret, prod);
        }

        // force negative number
        reverse(pos.begin(), pos.end());
        reverse(neg.begin(), neg.end());
        for (int p=0; p<=min(5, (int) pos.size()); p+=2) {
            if (5 - p > (int) neg.size())
                continue;
            long long prod = 1;
            for (int j=0; j<p; j++)
                prod *= pos[j];
            for (int j=0; j<5-p; j++)
                prod *= neg[j];
            ret = max(ret, prod);
        }

        cout << ret << "\n";
    }

    return 0;
}