#include<bits/stdc++.h>
using namespace std;

#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    const int DIM = 500;

    int N, M;
    cin >> N >> M;

    vi qual(N);
    for (int i = 0; i < N; i++) {
        cin >> qual[i];
    }

    N = DIM * DIM - DIM;
    qual.resize(N);

    vi order(N);
    for (int i = 0; i < N; i++) {
        order[i] = i;
    }
    sort(all(order), [&](int i, int j) {
        return qual[i] > qual[j];
    });

    vi ordered_qual = qual;
    sort(all(ordered_qual), greater<int>());

    vvi init(DIM, vi(DIM));
    vvi maxv(DIM, vi(DIM));
    vector<array<int, 2>> iupd(N);
    vector<array<int, 2>> mupd(N);

    vi diff(N + 1);
    for (int _i = 0; _i <= N; _i++) {
        if (_i % DIM == 0) {
            vi curv(DIM * DIM);
            for (int i = 0; i < N; i++) {
                curv[i] = diff[i] + (i ? curv[i-1] : 0);
                if (i % DIM == 0)
                    init[_i/DIM][i/DIM] = curv[i];
                maxv[_i/DIM][i/DIM] = max(curv[i], maxv[_i/DIM][i/DIM]);
            }

            WATCHC(curv);

            for (int ops = 0; ops < DIM && _i + ops < N; ops++) {
                int _j = _i + ops;
                int r = order[_j];
                int l = max(0, r - M + 1);

                iupd[_j] = { (l + DIM - 1) / DIM, r / DIM };
                mupd[_j] = { (l + DIM - 1) / DIM, (r + 1) / DIM - 1 };

                int last = -1;
                bool lres = false;
                auto incr_max = [&](int b) {
                    if (b < 0 || b >= DIM) return false;
                    if (b == last) return lres;
                    last = b;
                    int cmax = 0, nmax = 0;
                    for (int i = b * DIM; i < (b + 1) * DIM; i++) {
                        cmax = max(cmax, curv[i]);
                        if (l <= i && i <= r) curv[i]++;
                        nmax = max(nmax, curv[i]);
                    }
                    return lres = nmax > cmax;
                };

                if (incr_max(mupd[_j][0] - 1)) mupd[_j][0]--;
                if (incr_max(mupd[_j][1] + 1)) mupd[_j][1]++;

                TRACE(
                cout << "Update " << _j << " increments [ " << l << ", " << r << " ]" << endl;
                cout << "It increases init for " << iupd[_j][0] << " through " << iupd[_j][1] << endl;
                cout << "It increases maxv for " << mupd[_j][0] << " through " << mupd[_j][1] << endl;
                )
            }
        }

        if (_i < N) {
            int r = order[_i];
            int l = max(0, r - M + 1);
            diff[l]++;
            diff[r+1]--;
        }
    }

    int S, ans = 0;
    cin >> S;
    for (int d = 0; d < S; d++) {
        int l, r, x;
        cin >> l >> r >> x;

        l--, r--;
        x ^= ans;

        WATCH(x);

        int LIM = upper_bound(all(ordered_qual), x, greater<int>())
                - ordered_qual.begin();

        vi diff_init(DIM + 1), diff_maxv(DIM + 1);
        for (int _i = LIM/DIM*DIM; _i < LIM; _i++) {
            if (iupd[_i][0] <= iupd[_i][1]) {
                diff_init[iupd[_i][0]]++;
                diff_init[iupd[_i][1]+1]--;
            }
            if (mupd[_i][0] <= mupd[_i][1]) {
                diff_maxv[mupd[_i][0]]++;
                diff_maxv[mupd[_i][1]+1]--;
            }
        }

        WATCHC(diff_init);
        WATCHC(diff_maxv);

        vi spec_init = init[LIM/DIM];
        vi spec_maxv = maxv[LIM/DIM];

        WATCHC(spec_init);
        WATCHC(spec_maxv);

        int cur_diff_init = 0, cur_diff_maxv = 0;
        for (int b = 0; b < DIM; b++) {
            cur_diff_init += diff_init[b];
            cur_diff_maxv += diff_maxv[b];
            spec_init[b] += cur_diff_init;
            spec_maxv[b] += cur_diff_maxv;
        }

        WATCHC(spec_init);
        WATCHC(spec_maxv);

        int res = 0;
        for (int b = 0; b < DIM; b++) {
            int bl = b * DIM, br = bl + DIM - 1;
            if (l <= bl && br <= r) {
                res = max(res, spec_maxv[b]);
            } else if (max(l, bl) <= min(r, br)) {
                int val = spec_init[b];
                for (int i = bl; i <= br; i++) {
                    if (l <= i && i <= r) res = max(res, val);
                    if (qual[i] >= x) val--;
                    if (i+M<N && qual[i+M] >= x) val++;
                }
            }
        }

        ans = M - res;
        cout << ans << "\n";
    }

    return 0;
}