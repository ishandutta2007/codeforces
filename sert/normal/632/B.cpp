#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 7e5 + 34;
char s[N];
int a[N];
ll suma, sumb, sum0;
ll mx;
int n;

int main() {
   // freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    gets(s);
    gets(s);

    //puts(s);

    for (int i = 0; i < n; i++) if (s[i] == 'B') sum0 += a[i];

    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') sumb += a[i];
        else suma += a[i];
        if (suma - sumb > mx)
            mx = suma - sumb;
    }
    suma = sumb = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'B') sumb += a[i]; else suma += a[i];
        //cerr << suma << " " << sumb << "\n";
        mx = max(mx, suma - sumb);
    }
    cout << sum0 + mx;



    return 0;
}