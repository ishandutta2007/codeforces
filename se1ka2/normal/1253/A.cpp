#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        int a[100002], b[100002];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        int l = n, r = -1, k = 1;
        for(int i = 0; i < n; i++){
            if(a[i] != b[i]){
                l = i;
                k = b[i] - a[i];
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(a[i] != b[i]){
                r = i;
                break;
            }
        }
        if(k < 0){
            cout << "NO" << endl;
            continue;
        }
        bool f = true;
        for(int i = l; i <= r; i++){
            if(b[i] - a[i] != k){
                cout << "NO" << endl;
                f = false;
                break;
            }
        }
        if(f) cout << "YES" << endl;
    }
}