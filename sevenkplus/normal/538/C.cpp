#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int ld = -1, la;
int n, m; bool F = 1;
int S = 0;

int main () {
    cin >> n >> m;
    while (m --) {
        int d, a;
        cin >> d >> a;
        if (ld == -1) S = max(S, a+d-1); else {
            if (abs(a-la) > abs(d-ld)) F = 0; else {
                int t = abs(d-ld)-abs(a-la);
                S = max(S, max(a, la)+t/2);
            }
        }
        ld = d; la = a;
    }
    S = max(S, (n-ld)+la);
    if (F) printf ("%d\n", S);
    else puts ("IMPOSSIBLE");
    return 0; 
}