#include <iostream>
using namespace std;
const int N = 1000005;
int t, m, n, r, res, p[N], Q[N];
string s[N];

bool check(int i) {
    if (!r) return true;
    return i - Q[r] >= abs(p[i] - p[Q[r]]);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        res = 0;
        cin >> m >> n;
        for(int i=0; i<m; ++i) cin >> s[i];
        for(int i=0; i<m; ++i) p[i] = i & 1;
        while (true) {
            for(int i=0; i<m; ++i) {
                while (p[i] < n && s[i][p[i]] == '0') p[i] += 2;
                if (p[i] >= n) continue;
                if (check(i)) Q[++r] = i;
                else if (p[i] < p[Q[r]]) {
                    while (!check(i)) --r;
                    Q[++r] = i;
                }
            }
            if (!r) break;
            ++res;
            while (r) p[Q[r]] += 2, --r;
        }

        for(int i=0; i<m; ++i) p[i] = !(i & 1);
        while (true) {
            for(int i=0; i<m; ++i) {
                while (p[i] < n && s[i][p[i]] == '0') p[i] += 2;
                if (p[i] >= n) continue;
                if (check(i)) Q[++r] = i;
                else if (p[i] < p[Q[r]]) {
                    while (!check(i)) --r;
                    Q[++r] = i;
                }
            }
            if (!r) break;
            ++res;
            while (r) p[Q[r]] += 2, --r;
        }

        cout << res << '\n';
    }
}