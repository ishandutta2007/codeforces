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

    stringstream alpha;
    for (char c = 'a'; c <= 'z'; c++)
        alpha << c;
    string alphabet = alpha.str();

    string str;
    cin >> str;

    int loc = 0, ans = 0;
    for (char c : str) {
        int inx = alphabet.find(c);

        int dist = abs(inx - loc);
        dist = min(dist, 26 - dist);

        ans += dist;
        loc = inx;
    }

    cout << ans << endl;
    return 0;
}