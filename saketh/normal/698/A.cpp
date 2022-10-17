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

const int INF = INT_MAX / 2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vector<bool> cont(N, false), gym(N, false);

    for (int i = 0; i < N; i++) {
        int open;
        cin >> open;

        if (open & 1) cont[i] = true;
        if (open & 2) gym[i] = true;
    }

    vector<vector<int>> rest(N + 1, vector<int>(3, INF));

    rest[0][0] = 0;

    for (int i = 0; i < N; i++) {
        rest[i+1][0] = min({ rest[i][0], rest[i][1], rest[i][2] }) + 1;
        if (cont[i]) rest[i+1][1] = min({ rest[i][0], rest[i][2] });
        if (gym[i]) rest[i+1][2] = min({ rest[i][0], rest[i][1] });

        //cout << "After day " << i << " we have " << 
        //    rest[i+1][0] << " " << rest[i+1][1] << " " << rest[i+1][2] << endl;
    }

    cout << min( { rest[N][0], rest[N][1], rest[N][2] } ) << "\n";

    return 0;
}