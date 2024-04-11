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
    int N;
    cin >> N;

    vi arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vi order(N);
    for (int i = 0; i < N; i++) {
        order[i] = i;
    }
    sort(all(order), [&](int i, int j) {
        return arr[i] < arr[j];
    });

    int ans = 0, i = 0;
    for (int inx : order) {
        if (arr[inx] > arr[order[i]]) {
            ans++;
            i++;
        }
    }

    cout << ans << endl;
}