#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 5e5 + 10;
int _dn[2*MAXN], _up[2*MAXN], a[2*MAXN];
int *dn = _dn + MAXN, *up = _up + MAXN;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            dn[a[i]]++;
            a[i + 1] = a[i] - 1;
        }
        else {
            up[a[i]]++;
            a[i + 1] = a[i] + 1;
        }
    }
    /*for(int i = 0; i <= n; i++)
        cout << a[i] << " ";
    cout << '\n';
    for(int i = 0; i <= n; i++)
        cout << up[a[i]] << " ";
    cout << '\n';*/
    int cur = 0;
    for(int i = 0; i < n; i++) {
        if(dn[cur] > 0 && (up[cur - 1] || up[cur] + dn[cur] == 1)) {
            dn[cur]--;
            cur--;
        }
        else {
            up[cur]--;
            cur++;
        }
        a[i + 1] = cur;
    }
    //for(int i = 0; i <= n; i++)
    //    cout << a[i] << " ";
    //cout << '\n';
    for(int i = 1; i <= n; i++)
        cout << (a[i] > a[i - 1]);
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}