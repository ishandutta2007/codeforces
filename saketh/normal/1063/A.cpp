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

    sort(all(str));
    cout << str << endl;

    /*int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            bool pal = true;
            for (int k = i; k <= j; k++) {
                if (str[k] != str[j - (k - i)])
                    pal = false;
            }
            ans += pal;
        }
    }
    cout << ans << endl;*/

    return 0;
}