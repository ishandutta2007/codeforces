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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M, X;
    cin >> N >> M;
    vi a(N), b(M);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < M; i++)
        cin >> b[i];
    cin >> X;

    auto transform = [](vi &v) {
        vi res(v.size() + 1, INT_MAX/2);
        for (int i = 0; i < v.size(); i++) {
            int sum = 0;
            for (int j = i; j < v.size(); j++) {
                sum += v[j];
                res[j-i+1] = min(res[j-i+1], sum);
            }
        }
        return res;
    };

    a = transform(a);
    b = transform(b);

    int ans = 0;
    for (int ae = 1; ae <= N; ae++) {
        for (int be = 1; be <= M; be++) {
            if (a[ae] * 1ll * b[be] <= X)
                ans = max(ans, ae * be);
        }
    }
    cout << ans << endl;

    return 0;
}