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

    string s, t;
    cin >> s >> t;

    int wc = s.find('*');
    if (wc == string::npos) {
        cout << (s == t ? "YES" : "NO") << endl;
        return 0;
    }

    string front = s.substr(0, wc);
    string back = s.substr(wc + 1);

    bool match = (front.size() + back.size()) <= t.size();
    if (!match) {
        cout << "NO" << endl;
        return 0;
    }

    match &= front == t.substr(0, front.size());
    match &= back == t.substr(t.size() - back.size());

    cout << (match ? "YES" : "NO") << endl;
    return 0;
}