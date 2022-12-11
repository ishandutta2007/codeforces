#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

string s[100], t;
int n, m, ans;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++) {
            t.clear();
            for (int di = 0; di < 2; di++)
                for (int dj = 0; dj < 2; dj++)
                    t += s[di + i][dj + j];
            sort(t.begin(), t.end());
            if (t == "acef")
                ans++;
        }

    cout << ans;

    return 0;
}