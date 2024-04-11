#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[5002];
        for(int i = 0; i < n; i++) cin >> a[i];
        int l;
        for(l = 0; l < n; l++){
            if(a[l] != a[0]) break;
        }
        if(l == n){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for(int i = 1; i < n; i++){
            if(a[i] != a[0]) cout << 1 << " " << i + 1 << endl;
            else cout << l + 1 << " " << i + 1 << endl;
        }
    }
}