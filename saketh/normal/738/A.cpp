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
    string str;
    cin >> N >> str;

    for (int i = 0; i < N; ) {
        if (i + 2 < N && str.substr(i, 3) == "ogo") {
            i += 3;
            while (i + 1 < N && str.substr(i, 2) == "go")
                i+=2;
            cout << "***";
        } else {
            cout << str[i];
            i++;
        }
    }

    cout << endl;
    return 0;
}