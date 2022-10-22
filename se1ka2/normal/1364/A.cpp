#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int a[100005];
        int s = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s += a[i];
        }
        if(s % x){
            cout << n << endl;
            continue;
        }
        int l;
        for(l = 0; l < n; l++){
            if(a[l] % x) break;
        }
        int r;
        for(r = n - 1; r >= 0; r--){
            if(a[r] % x) break;
        }
        if(l == n){
            cout << -1 << endl;
        }
        else{
            cout << n - min(l + 1, n - r) << endl;
        }
    }
}