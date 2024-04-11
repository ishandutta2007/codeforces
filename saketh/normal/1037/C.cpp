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

vb read() {
    string str;
    cin >> str;
    vb res;
    for (char c : str)
        res.push_back(c == '1');
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;
    vb a = read(), b = read();

    vi steps(N + 1);
    for (int i = 1; i <= N; i++) {
        steps[i] = steps[i-1] + int(a[i-1] != b[i-1]);
        if (i > 1 && a[i-2] == b[i-1] && a[i-1] == b[i-2])
            steps[i] = min(steps[i], steps[i-2] + 1);
    }

    cout << steps.back() << endl;
    return 0;
}