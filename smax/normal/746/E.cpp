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

int a[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    int oddCnt = 0, evenCnt = 0;
    map<int, int> odd, even;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i] % 2) {
            odd[a[i]]++;
            oddCnt++;
        } else {
            even[a[i]]++;
            evenCnt++;
        }
    }

    int nextOdd = 1, nextEven = 2;
    while (odd.count(nextOdd)) nextOdd += 2;
    while (even.count(nextEven)) nextEven += 2;
    set<pair<int, int>, greater<pair<int, int>>> ost, est;
    for (auto p : odd)
        ost.insert({p.second, p.first});
    for (auto p : even)
        est.insert({p.second, p.first});

    int ret = 0;
    map<int, queue<int>> swaps;
    while (oddCnt != evenCnt || ost.begin()->first > 1 || est.begin()->first > 1) {
        if (oddCnt > evenCnt) {
            auto p = *ost.begin();
            DEBUG(1, p)
            ost.erase(ost.begin());
            if (nextEven > m) {
                cout << "-1\n";
                return 0;
            }
            if (--odd[p.second] == 0)
                odd.erase(p.second);
            else
                ost.insert({p.first - 1, p.second});
            even[nextEven]++;
            est.insert({1, nextEven});
            swaps[p.second].push(nextEven);
            nextEven += 2;
            while (even.count(nextEven)) nextEven += 2;
            oddCnt--, evenCnt++;
        } else if (oddCnt < evenCnt) {
            auto p = *est.begin();
            DEBUG(2, p)
            est.erase(est.begin());
            if (nextOdd > m) {
                cout << "-1\n";
                return 0;
            }
            if (--even[p.second] == 0)
                even.erase(p.second);
            else
                est.insert({p.first - 1, p.second});
            odd[nextOdd]++;
            ost.insert({1, nextOdd});
            swaps[p.second].push(nextOdd);
            nextOdd += 2;
            while (odd.count(nextOdd)) nextOdd += 2;
            oddCnt++, evenCnt--;
        } else if (ost.begin()->first > 1) {
            auto p = *ost.begin();
            DEBUG(3, p)
            ost.erase(ost.begin());
            if (nextOdd > m) {
                cout << "-1\n";
                return 0;
            }
            --odd[p.second];
            ost.insert({p.first - 1, p.second});
            odd[nextOdd]++;
            ost.insert({1, nextOdd});
            swaps[p.second].push(nextOdd);
            nextOdd += 2;
            while (odd.count(nextOdd)) nextOdd += 2;
        } else {
            auto p = *est.begin();
            DEBUG(4, p)
            est.erase(est.begin());
            if (nextEven > m) {
                cout << "-1\n";
                return 0;
            }
            --even[p.second];
            est.insert({p.first - 1, p.second});
            even[nextEven]++;
            est.insert({1, nextEven});
            swaps[p.second].push(nextEven);
            nextEven += 2;
            while (even.count(nextEven)) nextEven += 2;
        }
        ret++;
    }

    cout << ret << "\n";
    for (int i=0; i<n; i++) {
        if (swaps[a[i]].empty())
            cout << a[i] << " \n"[i==n-1];
        else {
            cout << swaps[a[i]].front() << " \n"[i==n-1];
            swaps[a[i]].pop();
        }
    }

    return 0;
}