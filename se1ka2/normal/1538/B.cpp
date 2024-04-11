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
        int s = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s += a[i];
        }
        if(s % n){
            cout << -1 << endl;
            continue;
        }
        s /= n;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > s) ans++;
        }
        cout << ans << endl;
    }
}