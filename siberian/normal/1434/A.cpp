#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int A = 6;
const int N = 1e5 + 10;
int n;
int a[A], b[N];

void read() {
    for (int i = 0; i < A; ++i) {
        cin >> a[i];
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
}

struct Event{
    int pos, ind;
};

bool operator<(const Event& a, const Event& b) {
    return a.pos < b.pos;
}

vector<Event> have;

int cnt;
int ans;
int used[N];

void build() {
    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < n; ++j) {
            have.push_back({b[j] - a[i], j});
        }
    }
    sort(all(have));
    cnt = 0;
}

void add(int x) {
    if (used[x] == 0) {
        cnt++;
    }
    used[x]++;
}

void del(int x) {
    if (used[x] == 1) {
        cnt--;
    }
    used[x]--;
}

void scanline() {
    ans = have.back().pos - have[0].pos;
    int r = 0;
    for (int l = 0; l < have.size(); ++l) {
        while (r < have.size() && cnt < n) {
            add(have[r].ind);
            ++r;
        }
        if (r == have.size()) {
            break;
        }
        chkmin(ans, have[r - 1].pos - have[l].pos);
        del(have[l].ind); 
    }
}

void run() {
    build();
    scanline();
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}