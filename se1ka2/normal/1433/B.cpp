#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[52];
        int l = 0, r = 0;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++){
            if(a[i] == 1){
                l = i;
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(a[i] == 1){
                r = i;
                break;
            }
        }
        int ans = 0;
        for(int i = l + 1; i < r; i++) ans += 1 - a[i];
        cout << ans << endl;
    }
}