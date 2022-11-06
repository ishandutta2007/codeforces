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

string solve(int n, vector<int> a) {
    for (int i = 32; i >= 0; --i) {
        int cnt = 0;
        for (auto x: a) {
            if (x & pw(i)) {
                ++cnt;
            }
        }

        if (cnt & 1) {
            if (((cnt >> 1) & 1) && !((n - cnt) & 1)) {
                return "LOSE\n";
            }
            return "WIN\n";
        }
    }
    return "DRAW\n";
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (auto& x: a) {
            scanf("%d", &x);
        }
        auto answer = solve(n, a);
        printf(answer.c_str());
    }
    return 0;
}