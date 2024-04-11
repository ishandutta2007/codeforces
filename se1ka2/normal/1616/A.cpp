#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int b[102]{0};
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            b[abs(a)]++;
        }
        int ans = min(1, b[0]);
        for(int i = 1; i <= 100; i++) ans += min(2, b[i]);
        cout << ans << endl;
    }
}