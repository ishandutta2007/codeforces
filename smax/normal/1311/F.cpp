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

struct Bit {
    int n;
    vector<long long> bit;

    Bit(int _n) : n(_n), bit(n + 1) {}

    long long query(int i) {
        long long ret = 0;
        for (; i>0; i-=i&-i)
            ret += bit[i];
        return ret;
    }

    void update(int i, long long val) {
        for (; i<=n; i+=i&-i)
            bit[i] += val;
    }
};

int x[200000], v[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> coords;
    for (int i=0; i<n; i++) {
        cin >> x[i];
        coords.push_back(x[i]);
    }
    vector<int> pos, neg, all, zero;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        if (v[i] >= 0)
            pos.push_back(i);
        if (v[i] <= 0)
            neg.push_back(i);
        if (v[i] == 0)
            zero.push_back(i);
        all.push_back(i);
    }

    map<int, int> compression;
    sort(coords.begin(), coords.end());
    for (int i=0; i<n; i++)
        compression[coords[i]] = i + 1;

    sort(pos.begin(), pos.end(), [&] (int a, int b) {
        if (v[a] == v[b])
            return x[a] < x[b];
        return v[a] < v[b];
    });

    long long ret = 0;
    Bit sum(n), num(n);
    for (int i : pos) {
        int y = compression[x[i]];
//        DEBUG(y, i, x[i], v[i], num.query(y), sum.query(y))
//        ret += (sum.query(n) - sum.query(y)) - (num.query(n) - num.query(y)) * x[i];
        ret += num.query(y) * x[i] - sum.query(y);
        sum.update(y, x[i]);
        num.update(y, 1);
    }

    DEBUG(ret)

    sort(neg.begin(), neg.end(), [&] (int a, int b) {
        if (v[a] == v[b])
            return x[a] < x[b];
        return -v[a] > -v[b];
    });
    sum = Bit(n), num = Bit(n);
    for (int i : neg) {
        int y = compression[x[i]];
        ret += num.query(y) * x[i] - sum.query(y);
        sum.update(y, x[i]);
        num.update(y, 1);
    }

    DEBUG(ret)
    sort(all.begin(), all.end(), [&] (int a, int b) {
        return x[a] < x[b];
    });
//    Bit lsum(n), lnum(n), rsum(n), rnum(n);
    long long totSum = 0, totNum = 0;
    for (int i : all) {
//        int y = compression[x[i]];
//        DEBUG(x[i], v[i], y)
        if (v[i] < 0) {
//            lsum.update(y, x[i]);
//            lnum.update(y, 1);
            totSum += x[i];
            totNum++;
        } else if (v[i] > 0) {
//            DEBUG(i, lnum.query(y), lsum.query(y))
//            ret += lnum.query(y) * x[i] - lsum.query(y);
            ret += totNum * x[i] - totSum;
        }
    }
    DEBUG(ret)
//    for (int j=n-1; j>=0; j--) {
//        int i = all[j];
//        int y = compression[x[i]];
//        if (v[i] >= 0) {
//            rsum.update(y, x[i]);
//            rnum.update(y, 1);
//        } else {
//            ret += rsum.query(n) - rnum.query(n) * x[i];
//        }
//    }

    sort(zero.begin(), zero.end(), [&] (int a, int b) {
        return x[a] < x[b];
    });
    totSum = 0, totNum = 0;
    for (int i : zero) {
        ret -= totNum * x[i] - totSum;
        totSum += x[i];
        totNum++;
    }

//    ret -= 1LL * z0 * (z0 - 1) / 2;

    cout << ret << "\n";

    return 0;
}