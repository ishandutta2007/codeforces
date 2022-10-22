#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int a[4005];
        for(int i = 0; i < n; i++) cin >> a[i];
        bool f = true;
        bool g = false;
        int s = 0;
        for(int i = 0; i < n; i++){
            if(a[i] != x) f = false;
            if(a[i] == x) g = true;
            s += a[i] - x;
        }
        if(f) cout << 0 << endl;
        else if(s == 0 || g) cout << 1 << endl;
        else cout << 2 << endl;
    }
}