#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[102];
        for(int i = 0; i < n; i++) cin >> a[i];
        int c = 1;
        for(int i = 1; i < n; i++){
            if(a[i] != a[i - 1]) c++;
        }
        if(k == 1 && c > 1){
            cout << -1 << endl;
            continue;
        }
        for(int ans = 1; ans <= 10000; ans++){
            if(ans * k - (ans - 1) >= c){
                cout << ans << endl;
                break;
            }
        }
    }
}