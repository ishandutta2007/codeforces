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

vi simulate(int N) {
    vi nums(N);
    for (int i = 0; i < N; i++)
        nums[i] = i;

    vi res(N);
    for (int r = 0; r < N; r++) {
        int inx = (nums.size()-1) / 2;
        auto it = nums.begin() + inx;
        res[r] = *it;
        nums.erase(it);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    string enc;
    cin >> N >> enc;

    vi where = simulate(N);
    WATCHC(where);

    vector<char> res(N);
    for (int i = 0; i < N; i++)
        res[where[i]] = enc[i];

    for (int i = 0; i < N; i++)
        cout << res[i];
    cout << endl;

    return 0;
}