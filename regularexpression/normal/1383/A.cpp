#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define pw(x) (1LL<<x)
#define epr(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)

#define db(x) cerr << #x << " = " << x << '\n'
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << '\n'

typedef long long ll;
typedef double dbl;

int solve(int n, string a, string b) {
    vector<vector<int>> e(20);
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            e[a[i] - 'a'].pb(b[i] - 'a');
        }
        if (a[i] > b[i]) {
            return -1;
        }
    }

    int res = 0;
    for (int i = 0; i < 20; ++i) {
        if (!e[i].empty()) {
            ++res;
            sort(all(e[i]));
            for (auto x: e[i]) {
                if (x != e[i][0]) {
                    e[e[i][0]].pb(x);
                }
            }
        }
    }

    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        string a, b;
        cin >> a >> b;
        int answer = solve(n, a, b);
        //db(answer);
        printf("%d\n", answer);
    }
    return 0;
}