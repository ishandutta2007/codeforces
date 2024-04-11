#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 1010

int n, m, a[N], b[N], p[N];
bool v[N];

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < m; i ++) {
        cin >> b[i]; b[i] --;
    }
    memset(p, -1, sizeof p);
    int S = 0;
    for (int i = 0; i < m; i ++) {
        memset(v, 0, sizeof v);
        for (int j = p[b[i]]+1; j < i; j ++) 
            if (!v[b[j]]) {
                S += a[b[j]]; v[b[j]] = 1;
            }
        p[b[i]] = i;
    }
    cout << S << endl;
    return 0; 
}