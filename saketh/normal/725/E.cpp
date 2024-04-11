#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const int SQRT = 500;

bool simulate(vector<int> &vals, int intro, int amt) {
    for (int v : vals) {
        if (intro >= v) {
            if (amt >= intro) {
                amt -= intro;
            }
            intro = INT_MAX;
        }

        if (amt >= v)
            amt -=v;
    }

    if (amt >= intro)
        amt -= intro;

    return amt == 0;
}

// find the first index >= i such that vals[index] <= v
// vals should be sorted in decreasing order
int search(vector<int> &vals, int i, int v) {
    int ans = vals.size();
    int lo = i, hi = ans - 1;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        if (vals[mi] <= v) {
            ans = mi;
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }
    return ans;
}

int fast_simulate(vector<int> &vals, int intro, int amt) {
    int i = 0;
    while (i < vals.size()) {
        int n = search(vals, i, amt);
        if (n == vals.size()) break;

        if (intro >= vals[n]) {
            if (amt >= intro)
                amt -= intro;
            intro = INT_MAX;
        }

        if (amt >= vals[n])
            amt -= vals[n];
        i = n + 1;
    }

    if (amt >= intro)
        amt -= intro;

    return amt;
}

vector<bool> calc_smalls(vi &smalls, int LIM) {
    vi qua(SQRT + 1);
    for (int v : smalls)
        qua[v]++;

    vector<bool> res(LIM + 1);
    for (int beg = 0; beg <= LIM; beg++) {
        int tmp = beg;
        for (int siz = SQRT; siz >= 1; siz--) {
            int take = min(qua[siz], tmp / siz);
            tmp -= take * siz;
        }
        res[beg] = !tmp;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int C, N;
    cin >> C >> N;

    vi vals(N);
    for (int i = 0; i < N; i++)
        cin >> vals[i];

    sort(all(vals));
    reverse(all(vals));

    for (int intro = 1; intro <= SQRT; intro++) {
        if (!simulate(vals, intro, C)) {
            cout << intro << endl;
            return 0;
        }
    }

    vi small, big;
    for (int v : vals) {
        if (v <= SQRT) small.push_back(v);
        else big.push_back(v);
    }

    sort(all(small));
    reverse(all(small));

    sort(all(big));
    reverse(all(big));

    vector<bool> can_do = calc_smalls(small, C);

    for (int intro = SQRT + 1; intro < C; intro++) {
        int rem = fast_simulate(big, intro, C);
        if (!can_do[rem]) {
            cout << intro << endl;
            return 0;
        }
    }

    cout << "Greed is good" << endl;
    return 0;
}