#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vll B(N / 2);
    for (int i = 0; i < N / 2; i++) {
        cin >> B[i];
    }

    vll A(N);

    int i = N/2 - 1, j = N/2;
    A[i--] = B.back() / 2;
    A[j++] = (B.back() + 1) / 2;

    for (int k = N/2 - 2; k >= 0; k--, i--, j++) {
        if (B[k] > B[k + 1]) {
            A[i] = A[i + 1];
            A[j] = A[j - 1] + B[k] - B[k + 1];
        } else {
            A[i] = A[i + 1] + B[k] - B[k + 1];
            A[j] = A[j - 1];
        }
    }

    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}