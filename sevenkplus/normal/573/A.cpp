#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

vector<int> a;
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int x; cin >> x;
        while (x%2 == 0) x/=2;
        while (x%3 == 0) x/=3;
        a.pb(x);
    }
    bool F = 1;
    for (int i = 1; i < n; i ++) 
        if (a[i] != a[0]) F = 0;
    puts (F?"Yes":"No");
    return 0;
}