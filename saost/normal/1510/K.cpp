#include <iostream>

using namespace std;
int n, a[2][2005];

int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n*2; ++i) {
        cin >> a[0][i];
        a[1][i] = a[0][i];
    }
    for(int i=0; i<=n; ++i) {
        bool ok = true;
        for(int j=1; j<=n*2; ++j) if (a[0][j] != j) { ok = false; break; }
        if (ok) { cout << i; return 0; }
        ok = true;
        for(int j=1; j<=n*2; ++j) if (a[1][j] != j) { ok = false; break; }
        if (ok) { cout << i; return 0; }
        for(int j=1; j<=n*2; j+=2) swap(a[i&1][j], a[i&1][j+1]);
        for(int j=1; j<=n; ++j) swap(a[i&1^1][j], a[i&1^1][j+n]);
    }
    cout << -1;
}