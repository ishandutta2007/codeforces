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

    int n;
    cin >> n;

    if (n == 2) {
        cout << "a1 a8 h8\n";
        return 0;
    }

    int r = 0, c = 0;

    auto print = [&] () {
        cout << " " << char('a' + c) << r + 1;
    };

    cout << "a1";
    for (int i=0; i<n-3; i++) {
        if (r == 6) {
            if (c == 0)
                c = 7;
            else if (c == 1)
                r++;
            else
                c--;
        } else if (r == 7) {
            c++;
        } else if (r % 2) {
            if (c == 0)
                r++;
            else
                c--;
        } else {
            if (c == 7)
                r++;
            else
                c++;
        }
        print();
    }

    if (c == 7) {
        if (r <= 4) {
            r++;
            print();
            r++;
            print();
            r = 7;
            print();
        } else {
            assert(r < 7);
            c--;
            print();
            r = 7;
            print();
            c = 7;
            print();
        }
    } else if (r == 7) {
        c = 6;
        print();
        c = 0;
        print();
        c = 7;
        print();
    } else if (c == 0) {
        r = 7;
        print();
        c++;
        print();
        c = 7;
        print();
    } else {
        r = 7;
        print();
        c = 0;
        print();
        c = 7;
        print();
    }
    cout << "\n";

    return 0;
}