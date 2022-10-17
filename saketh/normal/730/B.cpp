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

char query(int i, int j) {
    cout << "? " << i + 1 << " " << j + 1 << endl;
    char resp;
    cin >> resp;
    return resp;
}

void put_max(int &cur, int check) {
    if (query(cur, check) == '<')
        cur = check;
}

void put_min(int &cur, int check) {
    if (query(cur, check) == '>')
        cur = check;
}

pair<int, int> solve(int N) {
    assert(N % 2 == 0);

    vector<int> lows, highs;

    for (int i = 0; i < N; i += 2) {
        int res = query(i, i + 1);
        if (res == '<') {
            lows.push_back(i);
            highs.push_back(i+1);
        } else {
            lows.push_back(i+1);
            highs.push_back(i);
        }
    }

    int low = lows.front();
    for (int i = 1; i < lows.size(); i++)
        put_min(low, lows[i]);

    int high = highs.front();
    for (int i = 1; i < highs.size(); i++)
        put_max(high, highs[i]);

    return { low, high };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        if (N == 1) {
            cout << "! 1 1" << endl;
            continue;
        }

        int low, high;
        tie(low, high) = solve(N - (N & 1));

        if (N & 1) {
            put_min(low, N - 1);
            put_max(high, N - 1);
        }

        cout << "! " << low + 1 << " " << high + 1 << endl;
    }

    return 0;
}