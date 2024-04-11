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

    int N, M;
    cin >> N >> M;

    set<string> A, B;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        A.insert(str);
    }

    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        B.insert(str);
    }

    int both = 0;
    for (string str : A) {
        if (B.count(str))
            both++;
    }

    int p1 = A.size() - both + ((both+1)/2);
    int p2 = B.size() - both + ((both/2));

    if (p1 > p2) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}