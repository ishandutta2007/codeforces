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

// #define LOCAL

#ifdef LOCAL

int n = (ull)rnd() % 1000 + 2;
int fans = (ull)rnd() % n + 1;
// int n = 3;
// int fans = 1;
int curAns = fans;

#else

int n;

#endif

int oldAns = -1;

int query(int x) {
    if (x == 0) {
        assert(oldAns != -1);
        return oldAns;
    }
    assert(1 <= x && x < n);
    cout << "+ " << x << endl;
    int ans;
    #ifdef LOCAL
        curAns += x;
        ans = curAns / n;
    #else
        cin >> ans;
    #endif
    oldAns = ans;
    return ans;
}

int sum = 0;

//  ,  ans <= x
bool check(int x) {
    int need = ((n - x) % n + (n - sum % n)) % n;
    sum += need;
    cerr << "x = " << x << " need = " << need << endl;
    int has = query(need);
    cerr << "has = " << has << endl;
    cerr << "value = " << (x + sum) / n << endl;
    return (x + sum) / n <= has;
}

void outAns(int x) {
    cout << "! " << x + sum << endl;
    #ifdef LOCAL
        cerr << "fans = " << fans << endl;
        assert(x == fans);
    #endif
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    #ifdef LOCAL
        cerr << "n = " << n << " fans = " << fans << endl;
    #else
        cin >> n;
    #endif
    int L = 0, R = n + 1;
    while (L < R - 1) {
        int M = (L + R) / 2;
        if (check(M)) {
            L = M;
        } else {
            R = M;
        }
    }   
    outAns(L);
    return 0;
}