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

    string vowel = "aeiouy";

    int N;
    cin >> N;

    vi pat(N);
    for (int i = 0; i < N; i++)
        cin >> pat[i];

    string tmp;
    getline(cin, tmp);

    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);

        int vow = 0;
        for (char c : line) {
            if (vowel.find(c) != string::npos)
                vow++;
        }

        if (vow != pat[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}