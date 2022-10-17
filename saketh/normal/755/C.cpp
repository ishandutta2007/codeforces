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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;
    vi inp(N);
    for (int i = 0; i < N; i++) {
        cin >> inp[i];
        inp[i]--;
    }

    set<pair<int, int>> all;
    for (int i = 0; i < N; i++) {
        vi res;
        int loc = i;
        for (int j = 0; j < 400; j++) {
            res.push_back(loc);
            loc = inp[loc];
        }

        int v1 = res[res.size() - 2];
        int v2 = res[res.size() - 1];
        if (v1 > v2) swap(v1, v2);
        all.insert({v1, v2});
    }

    cout << all.size() << endl;
    return 0;
}