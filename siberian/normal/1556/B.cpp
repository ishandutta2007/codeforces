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

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}


long long get_swap_count(const vector<int> &vect) {
    long long odd_result = 0;
    long long even_result = 0;
    int cnt_odd = 0;
    int cnt_even = 0;
    for (int i = 0; i < vect.size(); i++) {
        if (vect[i] % 2 == 0) {
            //cnt_even * 2
            even_result += abs(i - cnt_even * 2);
            cnt_even++;
        }
        else {
            //cnt_odd * 2 + 1
            odd_result += abs(i - cnt_odd * 2);
            cnt_odd++;
        }
    }
    if (vect.size() % 2 == 0) {
        if (cnt_odd == cnt_even) {
            return min(odd_result, even_result);
        }
        return -1;
    }
    else {
        if (abs(cnt_odd - cnt_even) == 1) {
            if (cnt_odd > cnt_even)
                return odd_result;
            else
                return even_result;
        }
        return -1;
    }
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
        --i;
    }
    cout << get_swap_count(a) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }   
    return 0;
}