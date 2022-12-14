#include <iostream>
using namespace std;
long long t, n, a[200005], Q[200005];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        int l=0, r=0;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1, maxi=0; i<=n; i++) {
            if (a[i] > maxi) {
                while (a[i] > maxi) Q[++r] = ++maxi;
                cout << Q[r--] << ' ';
            } else cout << Q[++l] << ' ';
        }
        cout << '\n';
        r=0;
        for(int i=1, maxi=0; i<=n; i++) {
            while (a[i] > maxi) Q[++r] = ++maxi;
            cout << Q[r--] << ' ';
        }
        cout << '\n';
    }
}