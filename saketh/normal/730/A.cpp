#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) 
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    int sum = 0;

    vi rating(N);
    for (int i = 0; i < N; i++) {
        cin >> rating[i];
        sum += rating[i];
    }

    vi sorted = rating;
    sort(all(sorted));

    int rest = sum - sorted.back();
    int ans = sorted.front(), rem;

    while (ans > 0) {
        bool ok = true;

        if (sorted.back() - ans > rest - ans * (N - 1))
            ok = false;

        rem = sum - ans * N;
        if ((rem&1) && ((N == 2) || (sorted[N-3] == 0))) {
            ok = false;
        }

        if (ok) break;
        ans--;
    }
    
    cout << ans << "\n";
    vector<string> res;

    if (ans == 0) {
        for (int i = 0; i + 1 < N; i++) {
            for (int r = 0; r < sorted.back(); r++) {
                stringstream op;
                for (int j = 0; j < N; j++) {
                    if (j == i || j == i+1)
                        op << "1";
                    else op << "0";
                }
                res.push_back(op.str());
            }
        }
    } else {
        if (rem & 1) {
            stringstream op;
            int todo = 3;

            for (int i = 0; i < N; i++) {
                if (rating[i] > ans && todo > 0) {
                    op << "1";
                    rating[i]--;
                    todo--;
                    rem--;
                } else op << "0";
            }
            WATCH(op.str());
            res.push_back(op.str());
        }

        assert(rem % 2 == 0);

        while (rem) {
            int a = -1, b = -1;

            for (int i = 0; i < N; i++) {
                if (rating[i] > ans) {
                    if (a == -1) a = i;
                    else if (b == -1) b = i;
                    else {
                        if (rating[i] - ans > rating[a] - ans)
                            a = i;
                    }
                }
            }

            assert(b != -1);

            stringstream op;
            for (int i = 0; i < N; i++) {
                if (i == a || i == b) {
                    op << "1";
                    rating[i]--;
                    rem--;
                }
                else op << "0";
            }

            WATCH(op.str());
            WATCHC(rating);
            res.push_back(op.str());
        }
    }

    cout << res.size() << endl;
    for (string str : res)
        cout << str << endl;

    return 0;
}