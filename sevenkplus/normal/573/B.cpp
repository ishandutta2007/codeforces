#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 100010

int n;
int a[N];
int l[N], r[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) 
        cin >> a[i];
    l[0] = 1;
    for (int i = 1; i < n; i ++) {
        l[i] = l[i-1] + 1;
        l[i] = min(l[i], a[i]);
    }
    r[n-1] = 1;
    for (int i = n-2; i >= 0; i --) {
        r[i] = r[i+1] + 1;
        r[i] = min(r[i], a[i]);
    }
    int S = 0;
    for (int i = 0; i < n; i ++) 
        S = max(S, min(l[i], r[i]));
    cout << S << endl;
    return 0;
}