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

    map<int, int> lang;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int inp;
        cin >> inp;
        lang[inp]++;
    }

    int ans = 1;
    pair<int, int> best = { 0, 0 };

    int M;
    cin >> M;

    vi audio(M), subt(M);

    for (int i = 0; i < M; i++) {
        cin >> audio[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> subt[i];
    }

    for (int i = 0; i < M; i++) {
        pair<int, int> here = { lang[audio[i]], lang[subt[i]] };

        if (here > best) {
            best = here;
            ans = i + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}