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

    int M, N;
    string inp;

    cin >> M >> inp;
    N = inp.size();

    stringstream ans;

    for (char c = 'a'; c <= 'z'; c++) {
        int ls = -1, use = 0;

        while (ls + M < N) {
            int ns = -1;
            for (int inx = ls + 1; inx <= ls + M; inx++) {
                if (inp[inx] < c) {
                    use--;
                    ns = inx;
                    break;
                }

                if (inp[inx] == c)
                    ns = inx;
            }

            if (ns == -1) {
                break;
            } else {
                ls = ns;
                use++;
            }
        }

        if (ls + M < N) {
            for (char l : inp) {
                if (l == c)
                    ans << c;
            }
        } else {
            for (int i = 0; i < use; i++)
                ans << c;
            break;
        }
    }

    cout << ans.str() << endl;
    return 0;
}