#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto c=a; c!=b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE(cout << #V" = "; WATCHR(V.begin(), V.end()))

typedef long long ll;

template<typename T> struct kmp {
    int M;
    vector<T> needle;
    vector<int> succ;

    kmp(vector<T> _needle) {
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

    vector<bool> find(vector<T> &haystack) {
        int N = haystack.size(), i = 0;
        vector<bool> res(N);

        for (int m = 0; m + i < N; ) {
            if (i < M && needle[i] == haystack[m + i]) {
                if (i == M - 1) res[m] = true;
                i++;
            } else if (succ[i] != -1) {
                m = m + i - succ[i];
                i = succ[i];
            } else {
                i = 0;
                m++;
            }
        }

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N, W;
    cin >> N >> W;

    if (W == 1) { cout << N << "\n"; return 0; }

    vector<int> a(N), b(W);

    for (int &x : a)
        cin >> x;

    for (int &x : b)
        cin >> x;

    vector<int> ad(N - 1);
    for (int i = 0; i < N - 1; i++)
        ad[i] = a[i+1] - a[i];

    vector<int> bd(W - 1);
    for (int i = 0; i < W - 1; i++)
        bd[i] = b[i+1] - b[i];

    kmp<int> match(bd);
    vector<bool> where = match.find(ad);

    int tot = 0;
    for (bool b : where) {
        tot += b;
    }

    cout << tot << endl;
    return 0;
}