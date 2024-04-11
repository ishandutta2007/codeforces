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

vector<int> prices[3][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vi cost(N), a(N), b(N);

    for (int i = 0; i < N; i++)
        cin >> cost[i];

    for (int i = 0; i < N; i++)
        cin >> a[i];

    for (int i = 0; i < N; i++)
        cin >> b[i];
    
    for (int i = 0; i < N; i++) {
        a[i]--, b[i]--;
        prices[a[i]][b[i]].push_back(cost[i]);
    }

    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            sort(all(prices[a][b]), greater<int>());
        }
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int color;
        cin >> color;
        color--;

        int a = -1, b = -1, cost = INT_MAX;

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (prices[j][k].size() == 0) continue;
                if (j != color && k != color) continue;

                if (prices[j][k].back() < cost) {
                    cost = prices[j][k].back();
                    a = j;
                    b = k;
                }
            }
        }

        if (a == -1) cout << -1 << " ";
        else {
            cout << cost << " ";
            prices[a][b].pop_back();
        }
    }

    cout << endl;
    return 0;
}