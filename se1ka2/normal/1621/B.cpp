#include <iostream>
using namespace std;

const int INF = 1000000009;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a, b, ca, cb, cc;
        cin >> a >> b >> cc;
        ca = cc;
        cb = cc;
        bool all = true;
        cout << cc << endl;
        for(int i = 1; i < n; i++){
            int l, r, c;
            cin >> l >> r >> c;
            if(l <= a && r >= b){
                if(l == a && r == b && all) cc = min(cc, c);
                else cc = c;
                all = true;
            }
            if((l < a && r < b) || (l > a && r > b)) all = false;
            if(l < a){
                ca = c;
                a = l;
            }
            if(l == a) ca = min(ca, c);
            if(r > b){
                cb = c;
                b = r;
            }
            if(r == b) cb = min(cb, c);
            if(all) cout << min(ca + cb, cc) << endl;
            else cout << ca + cb << endl;
        }
    }
}