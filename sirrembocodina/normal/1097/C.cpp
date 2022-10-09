#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

string s[100100];
bool is[100100];
int cnt[500100];
int B[100100];
int MN[100100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n;
    cin >> n;    
    forn (i, n) {
        cin >> s[i];
        int b = 0, mn = 0;
        forn (j, s[i].size()) {
            if (s[i][j] == '(') {
                b++;
            } else {
                b--;
            }
            mn = min(mn, b);
        }
        if (mn >= 0) {
            is[i] = true;
            cnt[b]++;
        }
        B[i] = b;
        MN[i] = mn;
    }
    int ans = 0;
    forn (i, n) {
        if (is[i]) {
            continue;
        }
        if (B[i] != MN[i]) {
            continue;
        }
        if (cnt[-B[i]]) {
            cnt[-B[i]]--;
            ans++;
        }
    }
    ans += cnt[0] / 2;
    cout << ans << endl;
    return 0;
}