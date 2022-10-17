#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    string emp;

    cin >> N >> emp;

    int D = 0, R = 0;
    for (char c : emp) {
        if (c == 'D') D++;
        else R++;
    }

    vector<bool> vote(N, true);
    while (D > 0 && R > 0) {
        int DE = 0, RE = 0;
        for (int i = 0; i < N; i++) {
            if (!vote[i]) continue;
            if (emp[i] == 'D') {
                if (DE > 0) {
                    DE--;
                    vote[i] = false;
                    D--;
                } else RE++;
            } else {
                if (RE > 0) {
                    RE--;
                    vote[i] = false;
                    R--;
                } else DE++;
            }
        }

        for (int i = 0; i < N; i++) {
            if (!vote[i]) continue;
            if (emp[i] == 'D' && DE > 0) {
                DE--;
                vote[i] = false;
                D--;
            }
            if (emp[i] == 'R' && RE > 0) {
                RE--;
                vote[i] = false;
                R--;
            }
        }
    }

    if (D > 0) cout << 'D';
    else cout << 'R';
    cout << endl;
    return 0;
}