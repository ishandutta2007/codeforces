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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int sz = 0;
    long long tot = 0, doubleList = 0;
    set<long long> lightning, fire, doubleSt, pending;
    // THERE WILL ALWAYS BE ONE LIGHTNING WHO CANNOT BE DOUBLED
    // DON'T ADD THAT LIGHTNING SPELL TO PENDING
    int singleton = -1;
    for (int i=0; i<n; i++) {
        int tp;
        long long d;
        cin >> tp >> d;
        if (tp == 0) {
            if (d > 0) {
                fire.insert(d);
                tot += d;
                if (doubleSt.size() < sz) { // add
                    doubleList += d;
                    doubleSt.insert(d);
                } else if (sz > 0 && d > *doubleSt.begin()) {   // swap out
                    doubleList -= *doubleSt.begin();
                    pending.insert(*doubleSt.begin());
                    doubleSt.erase(doubleSt.begin());
                    doubleList += d;
                    doubleSt.insert(d);
                } else {    // leave it pending
                    pending.insert(d);
                }
            } else {
                d = -d;
                fire.erase(d);
                tot -= d;
                if (doubleSt.count(d)) {
                    doubleList -= d;
                    doubleSt.erase(d);
                    if (!pending.empty()) {
                        doubleList += *pending.rbegin();
                        doubleSt.insert(*pending.rbegin());
                        pending.erase(--pending.end());
                    }
                } else {
                    pending.erase(d);
                }
            }
        } else {
            if (d > 0) {
                lightning.insert(d);
                tot += d;
                sz++;
                if (singleton == -1) {
                    singleton = d;
                } else if (d < singleton) {
                    pending.insert(singleton);
                    singleton = d;
                } else {
                    pending.insert(d);
                }
                while (doubleSt.size() < sz && !pending.empty()) { // add
                    doubleList += *pending.rbegin();
                    doubleSt.insert(*pending.rbegin());
                    pending.erase(--pending.end());
                }
            } else {
                d = -d;
                lightning.erase(d);
                tot -= d;
                sz--;
                if (d == singleton) {   // find a new singleton replacement
                    if (!lightning.empty()) {
                        singleton = *lightning.begin();
                        if (doubleSt.count(singleton)) {
                            doubleList -= singleton;
                            doubleSt.erase(singleton);
                        } else {
                            pending.erase(singleton);
                        }
                    } else {
                        singleton = -1;
                    }
                } else if (doubleSt.count(d)) {
                    doubleList -= d;
                    doubleSt.erase(d);
                } else {
                    pending.erase(d);
                }
                while (doubleSt.size() > sz) {
                    doubleList -= *doubleSt.begin();
                    pending.insert(*doubleSt.begin());
                    doubleSt.erase(doubleSt.begin());
                }
            }
        }
        DEBUG(singleton, pending, doubleSt)
//        DEBUG(tot, !fire.empty() && !lightning.empty() ? *fire.rbegin() : 0, !lightning.empty() ? *lightning.begin() : 0)
//        cout << tot + (!fire.empty() && !lightning.empty() ? *fire.rbegin() : 0) - (!lightning.empty() ? *lightning.begin() : 0) << "\n";
        cout << tot + doubleList << "\n";
    }

    return 0;
}