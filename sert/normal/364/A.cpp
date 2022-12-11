#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e6 + 34;

int a;
string s;
ll k[N], sum, b[N];
ll ans;
ll c[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> a >> s;
    int n = s.length();
    for (int i = 0; i < n; i++)
        b[i] = s[i] - '0';
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; j < n; j++) {
            sum += b[j];
            k[sum]++;
        }
    }
    if (a == 0) {
        for (int i = 1; i < N; i++)
            ans += k[0] * k[i] * 2;
        ans += k[0] * k[0];
        cout << ans;
        return 0;
    }


    for (int i = 1; i * i <= a; i++) {
        if (a % i) continue;
        if (i * i < a) {
  if(a/i<N)          ans += 2 * k[i] * k[a / i];
 }        else
            ans += k[i] * k[i];
    }

    cout << ans;


    return 0;
}