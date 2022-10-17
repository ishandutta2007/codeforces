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

const int MAXV = 1005;
double prob[2][MAXV];
int when[2001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    vector<double> need(2001);
    for (int v = 0; v <= 2000; v++)
        need[v] = v / 2000.;

    int K;
    cin >> K;

    bool x = 0;
    prob[0][0] = 1;

    when[0] = 0;
    int next = 1;

    for (int d = 1;; d++) {
        for (int h = 0; h <= K; h++)
            prob[!x][h] = 0;

        for (int c = 0; c <= K; c++) {
            double get = double(K - c) / K;
            double stay = 1 - get;

            if (c < K) prob[!x][c + 1] += get * prob[x][c];
            prob[!x][c] += stay * prob[x][c];
        }

        x = !x;

        /*TRACE( if (d < 5) {
        cout << "On day " << d << endl;
        for (int c = 0; c <= K; c++)
            cout << "Chance to have " << c << " is " << prob[x][c] << endl;
        } )*/

        while (next <= 2000 && prob[x][K] > need[next]) {
            when[next] = d;
            next++;
        }

        if (next > 1010) {
            TRACE(cout << "Completed in " << d << " days" << endl);
            break;
        }
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int v;
        cin >> v;
        cout << when[v] << "\n";
    }

    return 0;
}