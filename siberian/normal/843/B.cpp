#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int Q = 2000;
const int B = 200;
int curQ = 0;
map<int, pair<int, int>> mem;

void query(int i, int& value, int& next) {
    if (mem.count(i)) {
        value = mem[i].first;
        next = mem[i].second;
    } else {
        assert(++curQ <= Q);
        cout << "? " << i + 1 << endl;
        cin >> value >> next;
        if (next != -1) --next;
        mem[i] = {value, next};
    }
}

void outAns(int ans) {
    assert(++curQ <= Q);
    cout << "! " << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int n, start, x;
    cin >> n >> start >> x;
    --start;
    int curPos = start, curValue, curNext;
    int value, next;
    query(curPos, curValue, curNext);
    while (curQ < min(n, B)) {
        int pos = (ull)rnd() % n;
        query(pos, value, next);
        if (curValue < value && value < x) {
            curPos = pos;
            curValue = value;
            curNext = next;
        }
    }
    query(curPos, curValue, curNext);
    while (curQ + 1 < Q && curNext != -1 && curValue < x) {
        curPos = curNext;
        query(curPos, curValue, curNext);
    }
    query(curPos, curValue, curNext);
    if (curValue >= x) {
        outAns(curValue);
    } else {
        outAns(-1);
    }
    return 0;
}