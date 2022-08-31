#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>
#include <cstring>
#include <cassert>


using namespace std;
//using namespace atcoder;

#define REP(i, n) for (int i=0; i<(n); ++i)
#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i, a, n) for (int i=(a); i<(n); ++i)
#define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl;

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    REP(i, SZ(v)) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

template<class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    return os << "(" << p.first << " " << p.second << ")";
}

template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

const ll MOD = 1e9 + 7;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;
const ld eps = 1e-9;


// edit

void solve() {
    int N, K;
    cin >> N >> K;
    vector<ll> A(N), D(N);
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> D[i];

    if (K >= 2) {
        ll sum = accumulate(ALL(A), 0ll);
        ll dec = *min_element(D.begin(), D.end() - 1);
        ll ans = sum - dec;
        chmax(ans, 0ll);
        chmax(ans, A[N - 1] - D[N - 1]);
        cout << ans << endl;
        return;
    }


    vector<ll> pre_min(N, LINF), pre_sum(N), suf_min(N, LINF), suf_sum(N), suf_val(N, LINF);
    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            pre_sum[i] = A[i];
            pre_min[i] = D[i];
        } else {
            pre_sum[i] = pre_sum[i - 1] + A[i];
            pre_min[i] = min(pre_min[i - 1], D[i]);
        }
    }
    for (int i = N - 1; i >= 0; --i) {
        if (i == N - 1) {
            suf_sum[i] = A[i];
            suf_min[i] = D[i];
//            suf_val[i] = A[i];
            suf_val[i] = LINF;
        } else {
            suf_sum[i] = suf_sum[i + 1] + A[i];
            suf_min[i] = min(suf_min[i + 1], D[i]);
            suf_val[i] = min(suf_val[i + 1], A[i]);
        }
    }

    if (K == 0) {
        ll ans = 0;
        for (int i = 0; i < N; ++i) {
            ll tmp = suf_sum[i] - D[i];
            chmax(ans, tmp);
        }
        cout << ans << endl;
        return;
    }

    vector<ll> suf_opt(N);
    for (int i = N - 1; i >= 0; --i) {
        if (i == N - 1) {
            suf_opt[i] = max(0ll, suf_sum[i] - D[i]);
        } else {
            suf_opt[i] = max(suf_opt[i + 1], suf_sum[i] - D[i]);
        }
    }

    ll ans = 0;
    for (int i = 1; i + 1 < N; ++i) {
        ll pre = max(0ll, pre_sum[i] - pre_min[i]);
        ll suf = suf_opt[i + 1];
        ll tmp = pre + suf;
        chmax(ans, tmp);
    }

    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            ll tmp = suf_sum[i] - suf_val[i + 1] - D[i];
            chmax(ans, tmp);
        } else {
            ll tmp = suf_sum[i] - D[i];
            chmax(ans, tmp);
        }
    }

//    ll tmp = suf_sum[0] - D[0] - suf_min[1];
    ll tmp = suf_sum[0] - D[0] - *min_element(D.begin() + 1, D.end() - 1);
    chmax(ans, tmp);

    cout << ans << endl;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
//    std::ifstream in("input.txt");
//    std::cin.rdbuf(in.rdbuf());

    solve();


    return 0;
}