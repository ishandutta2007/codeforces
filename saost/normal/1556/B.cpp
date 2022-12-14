#include <iostream>
using namespace std;
int t, n, a[100005];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        int cL = 0, cR = 0;
        for(int i=1; i<=n; ++i) {
            cin >> a[i]; a[i] %= 2;
            if (a[i]&1) ++cL; else ++cR;
        }
        if (abs(cL - cR) > 1) cout << "-1\n";
        else {
            long long res = 0, rL = 0, rC = 0;
            for(int i=1, d=1; i<=n; ++i) {
                if (a[i]) rL += abs(i - d), d+=2;
            }
            for(int i=1, d=1; i<=n; ++i) {
                if (!a[i]) rC += abs(i - d), d+=2;
            }
            if (cL < cR) res = rC;
            else if (cL > cR) res = rL;
            else res = min(rL, rC);
            cout << res << '\n';
        }
    }
}