//made by Sert
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;

int nx[N], pr[N], sk[N];
stack <int> a;
char ss[N], ch;
string s;
int n, m, p, r;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &p);
    p--;
    gets(ss);
    gets(ss);
    s = ss;

    a.push(0);

    for (int i = 0; i < n; i++) {
        nx[i] = i + 1;
        pr[i] = i - 1;
    }

    for (int i = 1; i < n; i++) {
        if (s[i] == '(')
            a.push(i);
        else {
            sk[a.top()] = i;
            sk[i] = a.top();
            a.pop();
        }
    }

    gets(ss);
    for (int i = 0; i < m; i++) {
        ch = ss[i];
        if (ch == 'L') {
            p = pr[p];
            continue;
        }
        if (ch == 'R') {
            p = nx[p];
            continue;
        }
        r = sk[p];
        if (r > p) swap(r, p);
        if (pr[r] != -1)
            nx[pr[r]] = nx[p];
        if (nx[p] != n)
            pr[nx[p]] = pr[r];
        if (nx[p] == n)
            p = pr[r];
        else
            p = nx[p];
    }

    while (pr[p] != -1)
        p = pr[p];
    while (p < n) {
        cout << s[p];
        p = nx[p];
    }


    return 0;
}