#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, u, v;
        cin >> n >> u >> v;
        int a[105];
        for(int i = 0; i < n; i++) cin >> a[i];
        bool f = false, g = false;
        for(int i = 0; i < n - 1; i++){
            if(abs(a[i] - a[i + 1]) >= 2) f = true;
            if(abs(a[i] - a[i + 1]) >= 1) g = true;
        }
        if(f) cout << 0 << endl;
        else if(g) cout << min(u, v) << endl;
        else cout << min(v * 2, u + v) << endl;
    }
}