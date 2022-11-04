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

vector<int> heap;
int h, g;
vector<int> ans;

bool push_max(int idx, bool first = true) {
    int l = 2 * idx + 1, r = 2 * idx + 2;
    if (heap[l] == 0 && heap[r] == 0) {
        if (idx + 1 < (1 << g)) {
            return false;
        } else {
            heap[idx] = 0;
            return true;
        }
    }
    if (heap[r] > heap[l]) {
        swap(heap[idx], heap[r]);
        if (push_max(r, false)) {
            if (first) {
                ans.pb(idx);
            }
            return true;
        }
        swap(heap[idx], heap[r]);
        return false;
    } else {
        swap(heap[idx], heap[l]);
        if (push_max(l, false)) {
            if (first) {
                ans.pb(idx);
            }
            return true;
        }
        swap(heap[idx], heap[l]);
        return false;
    }
}

void solve() {
    ans.clear();
    cin >> h >> g;
    heap.resize((1 << h) - 1, 0);
    for (auto &x : heap) {
        cin >> x;
    }
    heap.resize((1 << (h + 1)) - 1, 0);
    for (int i = 0; i < len(heap); ++i) {
        while (heap[i] && push_max(i));
    }
    cout << accumulate(all(heap), 0ll) << "\n";
    for (auto &x : ans) {
        cout << x + 1 << " ";
    }
    cout << "\n";
}

void run() {
    int n;
    cin >> n;
    while (n --> 0) {
        solve();
    }
}