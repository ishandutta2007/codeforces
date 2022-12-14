#include <iostream>
#define FOR(i,l,r) for(int i=l; i<=r; i++)
using namespace std;
int t, n, d, x;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> d;
        while (n--) {
            cin >> x;
            if (x >= d*10) { cout << "YES\n"; continue; }
            while (x>=0 && x%10 != d) x -= d;
            if (x>=0) cout << "YES\n"; else cout << "NO\n";
        }
    }
}