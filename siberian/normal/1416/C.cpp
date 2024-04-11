#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int N = 3e5 + 10;
int n;
int a[N];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

int fenwick[N];
vector<int> coord;

void upd(int pos) {
    //fenwick[pos]++;
    for (; pos < coord.size(); pos |= pos + 1) 
        ++fenwick[pos];
}

ll get(int r) {
    ll ans = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        ans += fenwick[r];
    }
    return ans;
}

ll calcInv(int x) {
    fill(fenwick, fenwick + coord.size(), 0);
    sort(all(coord), [&] (int a, int b) {
        return (a ^ x) < (b ^ x);
    });
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(all(coord), a[i], [&] (int myA, int myB) {
            return (myA ^ x) < (myB ^ x); 
        }) - coord.begin();
        ans += i - get(pos);
        upd(pos);
    }
    return ans;
    /*ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if ((a[i] ^ x) < (a[j] ^ x)) {
                ++ans;
            }
        }
    } 
    return ans;*/
}

ll ansInv;
int ansX;

void run() {
    for (int i = 0; i < n; ++i) {
        coord.push_back(a[i]);
    }
    sort(all(coord));
    coord.resize(unique(all(coord)) - coord.begin());
    ansInv = calcInv(0);
    ansX = 0;
    for (int bit = 29; bit >= 0; --bit) {
        ll put = calcInv(ansX ^ (1 << bit));
        ll notPut = ansInv;
        if (put < notPut) {
            ansX ^= (1 << bit);
        }
        ansInv = min(put, notPut);
    }
}

void write() {
    cout << ansInv << " " << ansX << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}