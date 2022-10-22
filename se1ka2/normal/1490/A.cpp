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
        for(int i = 0; i < n; i++) cin >> a[i];
        int ans = 0;
        for(int i = 1; i < n; i++){
            for(int j = 1; j < 10; j++){
                if((a[i] << j) < a[i - 1]) ans++;
                if((a[i - 1] << j) < a[i]) ans++;
            }
        }
        cout << ans << endl;
    }
}