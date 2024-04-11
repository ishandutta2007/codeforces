#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

struct kmp {
    int M;
    string needle;
    vi succ;

    kmp(string _needle) {
        needle = _needle;
        M = needle.size();

        succ.resize(M + 1);
        succ[0] = -1, succ[1] = 0;

        int cur = 0;
        for (int i = 2; i <= M; ) {
            if (needle[i-1] == needle[cur]) succ[i++] = ++cur;
            else if (cur) cur = succ[cur];
            else succ[i++] = 0;
        }
    }

    // returns first index, or -1 if no match
    int find(string &haystack) {
        int N = haystack.size(), i = 0;

        for (int m = 0; m + i < N; ) {
            if (i < M && needle[i] == haystack[m + i]) {
                if (i == M - 1) return m;
                i++;
            } else if (succ[i] != -1) {
                m = m + i - succ[i];
                i = succ[i];
            } else {
                i = 0;
                m++;
            }
        }

        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vs init(N), targ(N);
    for (int i = 0; i < N; i++)
        cin >> init[i];
    for (int i = 0; i < N; i++)
        cin >> targ[i];

    vi dmin(N, INT_MAX), dmax(N, -1);
    vi diff;
    for (int i = 0; i < N; i++) {
        int len = init[i].size();
        for (int j = 0; j < len; j++) {
            if (init[i][j] != targ[i][j]) {
                dmin[i] = min(dmin[i], j);
                dmax[i] = max(dmax[i], j);
            }
        }
        if (dmin[i] != INT_MAX) {
            diff.push_back(i);
        }
    }

    auto fail = []() {
        cout << "NO" << endl;
        exit(0);
    };

    assert(diff.size() > 0);
    int len = dmax[diff[0]] - dmin[diff[0]] + 1;
    for (int v : diff) {
        if ((dmax[v] - dmin[v] + 1) != len) {
            fail();
        }
    }

    auto match = [&](int off) {
        char ires = 0, tres = 0;
        for (int v : diff) {
            int inx = dmin[v] + off;
            if (inx < 0 || inx >= init[v].size())
                return false;
            if (ires == 0) {
                ires = init[v][inx];
                tres = targ[v][inx];
            } else {
                if (ires != init[v][inx])
                    return false;
                if (tres != targ[v][inx])
                    return false;
            }
        }
        return true;
    };
    for (int i = 0; i < len; i++) {
        if (!match(i)) fail();
    }

    int bef = 0, aft = 0;
    while (match(-(bef + 1)))
        bef++;
    while (match(len + aft))
        aft++;

    stringstream ss, st;
    for (int off = -bef; off < len + aft; off++) {
        ss << init[diff[0]][dmin[diff[0]] + off];
        st << targ[diff[0]][dmin[diff[0]] + off];
    }
    string s = ss.str(), t = st.str();

    kmp sf(s);
    for (int i = 0; i < N; i++) {
        int fm = sf.find(init[i]);
        if (dmin[i] == INT_MAX) {
            if (fm != -1) fail();
        } else {
            if (fm != dmin[i] - bef) fail();
        }
    }

    cout << "YES\n" << s << "\n" << t << "\n";
    return 0;
}