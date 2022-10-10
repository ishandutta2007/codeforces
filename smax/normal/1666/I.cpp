#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
// #define endl "\n"
const int inf = 1e18;

signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    
    int t;
    cin >> t;
    while(t--) {
        int n,m,r1,r2,r3,r4,r5;
        cin >> n >> m;
        
        cout << "SCAN 1 1" << endl;
        cin >> r1;
        cout << "SCAN " << n << " 1" << endl;
        cin >> r2;
        
        int xs = (r1-r2)/2 + 1 + n;
        int ys = (r1+r2)/2 - n + 3;
        
        cout << "SCAN " << xs/2 << " 1" << endl;
        cin >> r3;
        cout << "SCAN " << xs/2 << " " << ys/2 << endl;
        cin >> r4;

        int xd = r3-ys+2;
        int yd = r4-xd;
        
        cout << "DIG " << (xs+xd)/2 << " " << (ys+yd)/2 << endl;
        cin >> r5;
        
        if(r5==1) {
            cout << "DIG " << (xs-xd)/2 << " " << (ys-yd)/2 << endl;
            cin >> n;
        }
        else {
            cout << "DIG " << (xs+xd)/2 << " " << (ys-yd)/2 << endl;
            cin >> n;
            cout << "DIG " << (xs-xd)/2 << " " << (ys+yd)/2 << endl;
            cin >> n;
        }
        
        
        
    }
    
    return 0;
}