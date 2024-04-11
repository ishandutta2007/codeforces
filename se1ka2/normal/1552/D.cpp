#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[12];
        for(int i = 0; i < n; i++) cin >> a[i];
        int c = 1;
        for(int i = 0; i < n; i++) c *= 3;
        bool f = false;
        for(int b = 1; b < c; b++){
            int u = b;
            int s = 0;
            for(int i = 0; i < n; i++){
                if(u % 3 == 2) s -= a[i];
                else s += a[i] * (u % 3);
                u /= 3;
            }
            if(s == 0) f = true;
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}