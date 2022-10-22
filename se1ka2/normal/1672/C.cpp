#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        int l, r;
        for(l = 1; l < n; l++){
            if(a[l] == a[l - 1]) break;
        }
        for(r = n - 2; r >= 0; r--){
            if(a[r] == a[r + 1]) break;
        }
        if(r - l >= 0) cout << max(1, r - l) << endl;
        else cout << 0 << endl;
    }
}