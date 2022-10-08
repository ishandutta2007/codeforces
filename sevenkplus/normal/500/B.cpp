#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 310

int n, a[N]; string s[N]; bool v[N];

int main () {
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < n; i ++) cin >> s[i];
    for (int i = 0; i < n; i ++) s[i][i] = '1';
    for (int k = 0; k < n; k ++) 
        for (int i = 0; i < n; i ++) 
            for (int j = 0; j < n; j ++) 
                if (s[i][k] == '1' && s[k][j] == '1') s[i][j] = '1';
    for (int i = 0; i < n; i ++) if (!v[i]) {
        vector<int> b;
        vector<int> c;
        for (int j = 0; j < n; j ++) if (s[i][j] == '1') {
            b.pb(j); c.pb(a[j]); v[j] = 1;
        }
        sort(c.begin(), c.end());
        for (int j = 0; j < (int) b.size(); j ++) a[b[j]] = c[j];
    }
    for (int i = 0; i < n; i ++)
        printf ("%d%c", a[i], i == n-1?'\n': ' ');
    return 0; 
}