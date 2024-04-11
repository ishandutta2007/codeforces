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

bool test(long long a, long long b, long long m, long long power, vector<long long> ret) {
    if ((int) ret.size() > 1) {
        // greedily assign r_i from front
        long long need = b - (a * power + power), acc = 0;
        power /= 2;
        for (int i=1; i<(int)ret.size()-1; i++) {
            long long change = max(min(need / power, m - 1), 0LL);
            need -= power * change;
            ret[i] += acc / power + change;
            power /= 2;
            acc += power * change;
        }
    }
    long long sum = 0;
    for (int i=1; i<(int)ret.size(); i++) {
        sum += ret[i-1];
        if (!(ret[i] - sum >= 1 && ret[i] - sum <= m))
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        long long a, b, m;
        cin >> a >> b >> m;
        vector<long long> ret{a};
        long long power = 1;
        while (ret.back() < b) {
            // a * power + r_i, power <= r_i <= power * m
            if (a > (b - 1) / power)
                break;
            if (power <= b - a * power && (b - a * power) / m <= power) {
                ret.push_back(b);
                if (test(a, b, m, power, ret))
                    break;
                ret.pop_back();
            }
            ret.push_back(a * power + power);
            power *= 2;
        }
        if (ret.back() != b) {
            cout << "-1\n";
        } else {
            assert((int) ret.size() <= 50);
            if ((int) ret.size() > 1) {
                // greedily assign r_i from front
                long long need = b - (a * power + power), acc = 0;
                power /= 2;
                for (int i=1; i<(int)ret.size()-1; i++) {
                    long long change = max(min(need / power, m - 1), 0LL);
                    need -= power * change;
                    ret[i] += acc / power + change;
                    power /= 2;
                    acc += power * change;
                }
            }
            long long sum = 0;
            for (int i=1; i<(int)ret.size(); i++) {
                sum += ret[i-1];
                assert(ret[i] - sum >= 1 && ret[i] - sum <= m);
            }
            cout << ret.size();
            for (long long x : ret)
                cout << " " << x;
            cout << "\n";
        }
    }

    return 0;
}