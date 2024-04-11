#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define endl "\n"
//const int inf = 1e18;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        int c,d;
        cin >> c >> d;
        for(int x=0;x<m-1;x++) {
            int a,b;
            cin >> a >> b;
            c=max(c,a);
            d=max(d,b);
        }
        if(c+d<=n) {
            for(int x=0;x<c;x++) {
                cout << "R";
            }
            for(int x=c;x<n;x++) {
                cout << "W";
            }

            cout << endl;
        }
        else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}