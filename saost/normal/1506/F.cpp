#include <iostream>
#include <algorithm>
#define x first
#define y second
using namespace std;
long long t, n;
pair<int,int> a[200005];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        long long res = 0;
        for(int i=1; i<=n; i++) cin >> a[i].x;
        for(int i=1; i<=n; i++) cin >> a[i].y;
        sort(a+1, a+n+1);
        a[0] = {1,1};
        for(int i=1; i<=n; i++) {
            if (a[i].x - a[i].y == a[i-1].x - a[i-1].y) {
                if ((a[i].x + a[i].y) % 2 == 0) res += a[i].x - a[i-1].x;
                continue;
            }
            if ((a[i-1].x + a[i-1].y) % 2 == 0) a[i-1].x++;
            res += ((a[i].x - a[i].y) - (a[i-1].x - a[i-1].y) + 1) / 2;
        }
        cout << res << '\n';
    }
}