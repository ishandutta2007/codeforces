#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define mp make_pair
#define int ll

#define debug(x) cout << #x << " = " << x << endl;

const int INF = (is_same<int, ll>::value ? 1e18 + 666 : 1e9 + 666);

// const int MEM_SIZE = 5e8;
// char mem[MEM_SIZE];
// int cur_mem_ptr = 0;

// void* operator new(size_t n) {
//     cur_mem_ptr += n;
//     return mem + cur_mem_ptr - n;
// }

// void operator delete(void*) noexcept {}
// void operator delete(void*, size_t) noexcept {}

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

#ifndef LOCAL
void UseFiles(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
#else
void UseFiles(const string&) {}
#endif

void run();

signed main() {
    // UseFiles("squads");
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

int permute(int n, const vector<int> &p) {
    int ans = 0;
    for (int i = 0; i < len(p); ++i) {
        if (n & (1 << i))
            ans |= (1 << p[i]);
    }
    return ans;
}

void run() {
    // vector<pii> tests = { {2, 2},
    //                       {5, 24},
    //                       {35, 50}};
    // vector<int> p(6);
    // iota(all(p), 0);
    // do {
    //     int cnt = 0;
    //     for (auto &[x, y] : tests) {
    //         if (permute(x, p) != y) {
    //             ++cnt;
    //         } else {
    //             // cout << "check " << x << " " << y << endl;
    //         }
    //     }
    //     if (!cnt) {
    //         for (auto &x : p) {
    //             cout << x << " ";
    //         }
    //         cout << endl;
    //     } else {
    //         // cout << cnt << endl;
    //     }
    // } while (next_permutation(all(p)));
    const vector<int> p = {4, 1, 3, 2, 0, 5};
    int x;
    cin >> x;
    cout << permute(x, p) << endl;
}